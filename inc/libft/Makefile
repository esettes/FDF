GREEN	=\033[0;32m
BBLUE	=\033[1;34m
LBLUE	=\033[2;34m
LRED	=\033[2;31m
LYELLOW	=\033[2;33m
LWHITE	= \033[2;37m
LGREEN	=\033[2;32m

NAME	= libft.a

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC	= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

LIBINC	= ./inc/#libft.h
FLAGS	= -Wall -Wextra -Werror #-glldb
CC	= gcc

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) -I$(LIBINC) -o $@ -c $<
#	@echo "${LWHITE}Compiling $(notdir $<) ${LGREEN}✓$(RESET)"

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)\033[2;33m"

all: $(NAME) ${OBJDIR}

clean:
	@rm -rf $(OBJDIR)*.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all

.PHONY: re clean fclean all
