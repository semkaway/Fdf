# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvilna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 08:52:44 by kvilna            #+#    #+#              #
#    Updated: 2017/12/21 17:59:22 by kvilna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OPENGL_FLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = -I fdf.h

NAME = fdf

LIB = libft.a

SRC = main.c \
	algo_functions.c \
	turning_functions.c \
	read_functions.c \
	help_functions.c \
	turning_formulas.c \
	hex.c \
	color.c \
	bonus.c

OBG = $(SRC:.c=.o)

.PHONY: $(LIB)

all: $(LIB) $(NAME)

$(LIB):
	@make -C libft/

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

$(NAME): $(OBG)
	@$(CC) $(CFLAGS) $(HEADER) $(OPENGL_FLAGS) -o $(NAME) $(OBG) -L libft/ -lft

clean:
	@rm -f $(OBG) && make -C libft/ clean

fclean: clean
	@rm -f $(NAME) && make -C libft/ fclean

re: fclean all
