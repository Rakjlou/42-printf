# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:56:55 by nsierra-          #+#    #+#              #
#    Updated: 2021/11/29 20:24:15 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	state/state_default.c \
	state/state_conversion_flags.c \
	state/state_conversion_length.c \
	state/state_conversion_precision.c \
	state/state_conversion_print.c \
	state/state_wrong_flag.c \
	conversion/print_character.c \
	conversion/print_string.c \
	conversion/print_pointer.c \
	conversion/print_int.c \
	conversion/print_unsigned_int.c \
	conversion/print_hex_lowercase.c \
	conversion/print_hex_uppercase.c \
	conversion/print_flag.c \
	utils.c \
	print_op_debug_REMOVE_ME.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic
IFLAGS = -I./ -I./libft/
LFLAGS = -L. -lftprintf -L./libft/ -lft

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	ar rcs  $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft/ bonus

bonus: $(NAME)

test: $(NAME) tests.c
	gcc $(IFLAGS) tests.c $(LFLAGS) -o test && ./test

clean:
	make -C libft/ clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test bonus
