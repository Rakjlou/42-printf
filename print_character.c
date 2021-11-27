/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/27 21:41:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	print_character(t_printf_op *op, t_printf *state)
{
	int				raw;
	unsigned char	to_print;

	raw = va_arg(state->args, int);
	to_print = (unsigned int)raw;
	write(STDOUT_FILENO, &to_print, 1);
	state->bytes_printed += 1;
	(void)op;
}
