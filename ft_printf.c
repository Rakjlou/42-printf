/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:30:31 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/27 21:48:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

static void	init_state(t_printf *state)
{
	state->current = STATE_DEFAULT;
	state->bytes_printed = 0;
	state->callback[STATE_DEFAULT] = state_default;
	state->callback[STATE_CONVERSION] = state_conversion;
}

int	ft_printf(const char *format, ...)
{
	t_printf		state;
	unsigned int	current_state;

	if (format == NULL)
		return (-1);
	init_state(&state);
	va_start(state.args, format);
	while (state.current != STATE_END)
	{
		current_state = state.current;
		format = state.callback[current_state](format, &state);
	}
	va_end(state.args);
	return (state.bytes_printed);
}
