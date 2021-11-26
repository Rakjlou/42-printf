/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:10:19 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/26 04:41:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static const char	*load_op_config_options(const char *format, t_printf_op *op)
{
	while (*format && ft_strchr(FLAG_OPTIONS, (int)*format))
	{
		if (*format == ' ')
			op->blank = 1;
		else if (*format == '.')
			op->precision = 1;
		format++;
	}
	return (format);
}

static const char	*load_op_config(const char *format, t_printf_op *op)
{
	format = load_op_config_options(++format, op);
	return (format);
}

const char	*state_flag(const char *format, t_printf *state_machine)
{
	const char	*format_original;
	t_printf_op	op;

	(void)format_original;
	format_original = format;
	ft_bzero(&op, sizeof(t_printf_op));
	format = load_op_config(format, &op);
	(void)state_machine;
	return (format);
}
