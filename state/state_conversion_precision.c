/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_conversion_precision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:11:04 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/28 00:40:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*state_conversion_precision(const char *format, t_printf *state)
{
	state->current = STATE_CONVERSION_PRINT;
	if (*format != '.')
		return (format);
	state->op.precision = TRUE;
	++format;
	if (!ft_isdigit(*format) && *format != '\0')
		return (format);
	else if (*format == '\0')
	{
		state->current = STATE_WRONG_FLAG;
		return (format);
	}
	state->op.precision_value = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}
