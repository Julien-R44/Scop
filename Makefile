NAME	= HumanGL
DEBUG	= yes
ifeq ($(DEBUG),no)
	FLAGS=-Wall -Wextra -Werror
else
	FLAGS= -g
endif
SRC		= \
				main.c init.c
OBJ		= $(SRC:.c=.o)
SRCDIR	= ./src/
OBJDIR	= ./obj/
INCDIR	= ./inc/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))
INCS	= $(addprefix $(INCDIR), $(INC))
LDFLAGS	= -I./inc/ -I./libft/include/ -I./libmath/inc/ -I /usr/include/GL/
LIBFLAG = -L./libft/ -lft -L./libmath/ -lmath -lSDL2 -lglut -lGLU -lGL -lXmu -lX11 -lm

.SILENT:

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	make -C libft/
	make -C libmath/
	gcc $(FLAGS) -o $@ $^ $(LIBFLAG)
	echo "\\033[1;32mSuccess.\\033[0;39m"

$(OBJS): $(SRCS)
ifeq ($(DEBUG),yes)
	echo "\\033[1;31mDEBUG COMPILATION.. (no flags except -g)\\033[0;39m"
else
	echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
	echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	mkdir -p $(OBJDIR)
	mv $(OBJ) $(OBJDIR)

.PHONY: clean fclean re

clean:
	echo "\\033[1;34mDeleting objects...\\033[0;39m"
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	make fclean -C libmath/
	echo "\\033[1;34mDeleting $(NAME)\\033[0;39m"
	rm -f $(NAME)

re: fclean all
