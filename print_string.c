/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/27 21:41:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	print_string(t_printf_op *op, t_printf *state)
{
	char	*to_print;
	size_t	source_size;

	to_print = va_arg(state->args, char *);
	if (to_print == NULL)
		to_print = NULLSTR_PLACEHOLDER;
	source_size = ft_strlen(to_print);
	write(STDOUT_FILENO, to_print, source_size);
	state->bytes_printed += (int)source_size;
	(void)op;
}
