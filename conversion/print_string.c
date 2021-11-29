/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/29 23:16:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	print_padding(size_t size)
{
	size_t	i;

	i = 0;
	while (i++ < size)
		write(STDOUT_FILENO, " ", 1);
}

void	print_string(t_printf *state)
{
	char	*to_print;
	size_t	source_size;

	to_print = va_arg(state->args, char *);
	if (to_print == NULL)
		to_print = NULLSTR_PLACEHOLDER;
	source_size = ft_strlen(to_print);
	if (state->op.length == FALSE || state->op.length_value < source_size)
	{
		write(STDOUT_FILENO, to_print, source_size);
		state->bytes_printed += (int)source_size;
		return ;
	}
	else if (state->op.justified_left == TRUE)
	{
		write(STDOUT_FILENO, to_print, source_size);
		print_padding(state->op.length_value - source_size);
	}
	else
	{
		print_padding(state->op.length_value - source_size);
		write(STDOUT_FILENO, to_print, source_size);
	}
	state->bytes_printed += (int)state->op.length_value;
}
