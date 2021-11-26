# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:56:55 by nsierra-          #+#    #+#              #
#    Updated: 2021/11/26 23:15:22 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	state_default.c \
	state_flag.c \
	print_character.c \
	print_string.c \
	print_pointer.c \
	print_int.c \
	print_unsigned_int.c \
	print_hex_lowercase.c \
	print_hex_uppercase.c \
	print_flag.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic
IFLAGS = -I./ -I./libft/
LFLAGS = -L. -lftprintf -L./libft/ -lft

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft/ bonus

test: $(NAME) tests.c
	gcc $(IFLAGS) $(LFLAGS) tests.c $(LFLAGS) -o test && ./test

clean:
	make -C libft/ clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
