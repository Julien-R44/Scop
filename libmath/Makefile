# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 00:27:00 by jripoute          #+#    #+#              #
#    Updated: 2015/10/25 05:54:01 by y0ja             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libmath.a
CC		= gcc
SRC		= \
		math/ft_pow.c \
		math/ft_sqrtf.c \
		mat4/ft_mat4identity.c \
		mat4/ft_mat4perspective.c \
		mat4/ft_mat4lookAt.c \
		vec3/ft_vec3cross.c \
		vec3/ft_vec3length.c \
		vec3/ft_vec3normalize.c \
		vec3/ft_vec3sub.c

SRCDIR	= ./src/
OBJDIR	= ./obj/
INCDIR	= ./inc/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS 	= $(addprefix $(OBJDIR), $(patsubst %.c, %.o,$(SRC)))
INCS	= $(addprefix -I , $(INCDIR))
DIRSOBJ	= $(sort $(dir $(OBJS)))
DEBUG=yes
ifeq ($(DEBUG),no)
	CFLAGS = -Wall -Wextra -Werror
else
	CFLAGS = -g
endif

.PHONY: clean fclean re

.SILENT:

all: $(NAME)

$(NAME): makedir $(OBJS)
	echo "\\033[1;34mIndexing the lib...\\033[0;39m"
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "\\033[1;32mSuccess.\\033[0;39m"

makedir:
ifeq ($(DEBUG),no)
	echo "\\033[1;31mDebug compilation.. (-Wall -Wextra -Werror)\\033[0;39m"
else
	echo "\\033[1;31mNo flags.\\033[0;39m"
endif
	echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	mkdir -p $(OBJDIR)
	mkdir -p $(DIRSOBJ)

$(OBJDIR)%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $< $(INCS) $(CFLAGS) -lm

clean:
	echo "\\033[1;34mDeleting objects...\\033[0;39m"
	rm -f $(OBJS)

fclean: clean
	echo "\\033[1;34mDeleting libft.a...\\033[0;39m"
	rm -f $(NAME)

re: fclean all
