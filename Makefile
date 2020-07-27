# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljanette <ljanette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 02:25:09 by ljanette          #+#    #+#              #
#    Updated: 2020/07/26 21:47:38 by ljanette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_char.c ft_printf_num.c ft_printf_utils.c ft_printf_parser.c \
ft_putchar.c ft_putstr.c ft_strlen.c ft_strdup.c
NAME=libftprintf.a
OBJ_FILES=$(SRC:.c=.o)
INC=./

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)
#	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
