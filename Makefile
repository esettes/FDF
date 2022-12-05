# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 19:38:39 by iostancu          #+#    #+#              #
#    Updated: 2022/11/23 23:30:09 by iostancu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.POSIX:

GREEN	=\033[0;32m
WHITE	= \033[0;37m
BWHITE	= \033[1;37m
LGREEN	=\033[2;32m
LWHITE	= \033[2;37m
RESET	= \033[2;33m

G_CHECK = ${LGREEN}✓$(RESET)
G_OK = ${GREEN}[OK]$(RESET)

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
	LDLIBS			=	-lm
	LIBX42_FLAGS	=	-I include -ldl -lglfw $(LDLIBS)
endif

HEADERS	= -I include -I ./inc/libft/inc/ -I ./inc/gnl/inc/ -I ./inc/headers/ -I ./inc/MLX42/include/MLX42/

CC	= clang
CFLAGS	= #-Wall -Wextra -Werror #-Ofast #-g3   -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize=address -glldb
WINFLAGS	= -lglfw3 -lopengl32 -lgdi32
MFLAGS	= -lpthread -framework OpenGL -framework AppKit #-lmlx  -Lmlx

all: obj $(COMPS) $(NAME) #$(OBJDIR)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo "${LWHITE}Compiling $(notdir $<) $(G_CHECK)"
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

#Change libx42_flags position at the end of the coommand
$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(HEADERS) -o $(NAME) $(OBJS) $(COMPS) $(LIBX42_FLAGS) 
	@echo "${LWHITE}$(NAME) $(G_CHECK)"
	@echo "${BWHITE}Compilation $(G_OK)" 

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
	@echo "${LWHITE}Clean debug files... $(G_CHECK)"

clean:	dbgfiles
	@echo "${LWHITE}Clean fdf... $(G_CHECK)"
	@rm -rf ${OBJDIR}*.o
	@echo "${LWHITE}Clean Libft... $(G_CHECK)"
	@$(MAKE) -C $(dir $(LIBFT)) clean
	@echo "${LWHITE}Clean GNL... $(G_CHECK)"
	@$(MAKE) -C $(dir $(GNL)) clean
	@echo "${LWHITE}Clean MLX2... $(G_CHECK)"
	@$(MAKE) -C $(dir $(LIBX42)) clean
	@echo "${BWHITE}Clean objs $(G_OK)"

fclean: dbgfiles
	@rm -rf $(NAME)
#	@rm -rf $(LIBX42)
	@echo "${LWHITE}Clean fdf... $(G_CHECK)"
	@rm -rf ${OBJDIR}*.o
	@echo "${LWHITE}Clean Libft... $(G_CHECK)"
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@echo "${LWHITE}Clean GNL... $(G_CHECK)"
	@$(MAKE) -C $(dir $(GNL)) fclean
#	@echo "${LWHITE}Clean MLX42... $(G_CHECK)"
#	@$(MAKE) -C $(dir $(LIBX42)) clean
	@echo "${BWHITE}Clean all $(G_OK)"
	@echo "\n"

re: fclean all

.PHONY: all fclean clean re
