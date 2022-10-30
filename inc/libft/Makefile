LWHITE	= \033[2;37m
LGREEN	=\033[2;32m
RESET	= \033[2;33m

NAME	= libft.a

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC	= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

LIBINC	= ./inc/#libft.h
FLAGS	= -g3 -Wall -Wextra -Werror #-glldb
CC	= clang

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) -I$(LIBINC) -o $@ -c $<
#	@echo "${LWHITE}Compiling $(notdir $<) ${LGREEN}✓$(RESET)"

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)"

all: obj	$(NAME) ${OBJDIR}

obj:
	mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)*.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all

.PHONY: re clean fclean all