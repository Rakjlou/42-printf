/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:10:19 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/27 22:11:37 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static const char	*load_blank_option(const char *format, t_printf_op *op)
{
	while (*format == ' ')
		format++;
	op->blank = TRUE;
	return (format);
}

static const char	*load_precision_option(const char *format, t_printf_op *op)
{
	format++;
	op->precision = TRUE;
	op->precision_value = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static const char	*load_op_config_options(const char *format, t_printf_op *op)
{
	while (*format && ft_strchr(FLAGS, *format))
	{
		if (*format == ' ' && op->blank == FALSE)
		{
			format = load_blank_option(format, op);
			continue ;
		}
		else if (*format == '.' && op->precision == FALSE)
		{
			format = load_precision_option(format, op);
			continue ;
		}
		else if (*format == '#' && op->alternative == FALSE)
			op->alternative = TRUE;
		else if (*format == '0' && op->padding == FALSE)
			op->padding = TRUE;
		else if (*format == '-' && op->justified_left == FALSE)
			op->justified_left = TRUE;
		else if (*format == '+' && op->force_plus == FALSE)
			op->force_plus = TRUE;
		format++;
	}
	return (format);
}

static void	dispatch_op(t_printf_op *op, t_printf *state)
{
	void	(*callback[9])(t_printf_op *op, t_printf *state);

	callback[0] = print_character;
	callback[1] = print_string;
	callback[2] = print_pointer;
	callback[3] = print_int;
	callback[4] = print_int;
	callback[5] = print_unsigned_int;
	callback[6] = print_hex_lowercase;
	callback[7] = print_hex_uppercase;
	callback[8] = print_flag;
	callback[ft_strchr(CONV_SPECIFIERS, op->type) - CONV_SPECIFIERS](op, state);
}

const char	*state_conversion(const char *format, t_printf *state)
{
	const char	*format_original;
	t_printf_op	op;

	format_original = format;
	state->current = STATE_DEFAULT;
	ft_bzero(&op, sizeof(t_printf_op));
	format = load_op_config_options(++format, &op);
	if (ft_strchr(CONV_SPECIFIERS, *format) == NULL)
	{
		state->bytes_printed += 1;
		write(STDOUT_FILENO, "%", 1);
		return (++format_original);
	}
	op.type = *format++;
	dispatch_op(&op, state);
	return (format);
}
