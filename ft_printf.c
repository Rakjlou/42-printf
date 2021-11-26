/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:30:31 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/26 23:52:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

static void	init_state_machine(t_printf *state_machine)
{
	state_machine->state = STATE_DEFAULT;
	state_machine->bytes_printed = 0;
	state_machine->callback[STATE_DEFAULT] = state_default;
	state_machine->callback[STATE_FLAG] = state_flag;
}

int	ft_printf(const char *format, ...)
{
	t_printf		state_machine;
	unsigned int	state;

	if (format == NULL)
		return (-1);
	init_state_machine(&state_machine);
	va_start(state_machine.args, format);
	while (format && *format && state_machine.state != STATE_END)
	{
		state = state_machine.state;
		format = state_machine.callback[state](format, &state_machine);
	}
	va_end(state_machine.args);
	return (0);
}
