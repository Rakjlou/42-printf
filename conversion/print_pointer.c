/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/28 06:23:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	print_pointer(t_printf *state)
{
	unsigned long	raw;
	char			*to_print;
	size_t			to_print_size;

	raw = va_arg(state->args, unsigned long);
	if (raw == 0)
	{
		to_print = NULL_PLACEHOLDER;
		to_print_size = ft_strlen(NULL_PLACEHOLDER);
		write(STDOUT_FILENO, to_print, to_print_size);
		state->bytes_printed += to_print_size;
	}
	else
	{
		to_print = ft_utoa_base(raw, "0123456789abcdef", 16);
		to_print_size = ft_strlen(to_print);
		write(STDOUT_FILENO, "0x", 2);
		write(STDOUT_FILENO, to_print, to_print_size);
		free(to_print);
		state->bytes_printed += (int)to_print_size + 2;
	}
}
