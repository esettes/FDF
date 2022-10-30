GREEN	=\033[0;32m
LWHITE	= \033[2;37m
LGREEN	=\033[2;32m

NAME	= gnl.a

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC	= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

LIBINC	= ./inc/#get_next_line_bonus.h
FLAGS	= -g3 -Wall -Wextra -Werror
CC	= clang

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) -I$(LIBINC) -o $@ -c $< 
#	@echo "${LWHITE}Compiling $(notdir $<)${LGREEN}✓$(RESET)"

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(LWHITE)\033[2;33m"

all: obj	$(NAME) ${OBJS}

obj:
	mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)*.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
