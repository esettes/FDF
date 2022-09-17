# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 19:38:39 by iostancu          #+#    #+#              #
#    Updated: 2022/09/08 18:51:42 by iostancu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=\033[0;32m
WHITE	= \033[0;37m
BWHITE	= \033[1;37m
LGREEN	=\033[2;32m
LWHITE	= \033[2;37m

NAME	= fdf

OS		=	$(shell uname -s)

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC	= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

GNL	= ./inc/gnl/gnl.a
LIBFT	= ./inc/libft/libft.a
LIBX42	= ./inc/MLX42/libmlx42.a
COMPS	= $(GNL) $(LIBFT) $(LIBX42)



ifeq ($(OS), Darwin)
	LIBX42_FLAGS	=	-I include -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/
else
	LIBX42_FLAGS	=	-I include -ldl -lglfw -lm 	
endif

HEADERS	= -I include -I ./inc/libft/inc/ -I ./inc/gnl/inc/ -I ./inc/headers/ -I ./inc/MLX42/include/MLX42/

CC	= gcc
CFLAGS	= -g # -fsanitize=address #-fno-omit-frame-pointer # -Wall -Wextra -Werror # -Lmlx -lmlx -framework OpenGL -framework AppKit -glldb
WINFLAGS	= -lglfw3 -lopengl32 -lgdi32
MFLAGS	= -lpthread -framework OpenGL -framework AppKit #-lmlx  -Lmlx

all: obj $(LIBFT) $(GNL) $(LIBX42) $(NAME) #$(OBJDIR)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
#	@echo "${LWHITE}Compiling $(notdir $<) ${LGREEN}✓$(RESET)"
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

#Change libx42_flags position at the end of the coommand
$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(LIBX42) $(LIBX42_FLAGS) 
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)\033[2;33m"
	@echo "${BWHITE}Compilation ${GREEN}[OK]$(RESET)\033[2;33m" 

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT))

$(GNL):
	@$(MAKE) -C $(dir $(GNL))

$(LIBX42):
	@$(MAKE) -C $(dir $(LIBX42))

LD_DEBUG=all

dbgfiles:
	@rm -rf *.dSYM
	@rm -rf *.DS_Store
	@echo "${LWHITE}Clean debug files... ${LGREEN}✓$(RESET)\033[2;33m"

clean:	dbgfiles
	@echo "${LWHITE}Clean fdf... ${LGREEN}✓$(RESET)\033[2;33m"
	@rm -rf ${OBJDIR}*.o
	@echo "${LWHITE}Clean Libft... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(LIBFT)) clean
	@echo "${LWHITE}Clean GNL... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(GNL)) clean
	@echo "${LWHITE}Clean MLX2... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(LIBX42)) clean
	@echo "${BWHITE}Clean objs ${GREEN}[OK]$(RESET)\033[2;33m"

fclean: dbgfiles
	@rm -rf $(NAME)
	@rm -rf $(LIBX42)
	@echo "${LWHITE}Clean fdf... ${LGREEN}✓$(RESET)\033[2;33m"
	@rm -rf ${OBJDIR}*.o
	@echo "${LWHITE}Clean Libft... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@echo "${LWHITE}Clean GNL... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(GNL)) fclean
#	@echo "${LWHITE}Clean MLX42... ${LGREEN}✓$(RESET)"
	@$(MAKE) -C $(dir $(LIBX42)) clean
	@echo "${BWHITE}Clean all ${GREEN}[OK]\033[2;33m"
	@echo "\n"

re: fclean all

.PHONY: all fclean clean re
