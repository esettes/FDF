# Normal
GREEN	=\033[0;32m
CYAN	= \033[0;36m
# Bold
BCYAN	=\033[1;36m
# Low intensity
LCYAN	=\033[2;36m
LRED	=\033[2;31m
LYELLOW	=\033[2;33m
LWHITE	= \033[2;37m
LGREEN	=\033[2;32m

NAME	= gnl.a

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC	= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

LIBINC	= ./inc/#get_next_line_bonus.h
FLAGS	= -g -O0 -Wall -Wextra -Werror
CC	= gcc

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) -I$(LIBINC) -o $@ -c $< 
#	@echo "${LWHITE}Compiling $(notdir $<)${LGREEN}✓$(RESET)"

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(LWHITE)\033[2;33m"

all: $(NAME) ${OBJS}

clean:
	@rm -rf $(OBJDIR)*.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
