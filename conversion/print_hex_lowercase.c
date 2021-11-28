/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/28 03:53:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	print_hex_lowercase(t_printf *state)
{
	unsigned int	raw;
	char			*to_print;
	size_t			to_print_size;

	raw = va_arg(state->args, unsigned int);
	to_print = ft_utoa_base(raw, "0123456789abcdef", 16);
	to_print_size = ft_strlen(to_print);
	write(STDOUT_FILENO, to_print, to_print_size);
	state->bytes_printed += (int)to_print_size;
	free(to_print);
}
