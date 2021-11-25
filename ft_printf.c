/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:30:31 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:10:08 by nsierra-         ###   ########.fr       */
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

	init_state_machine(&state_machine);
	if (format == NULL)
		return (-1);
	while (format && *format && state_machine.state != STATE_END)
	{
		state = state_machine.state;
		format = state_machine.callback[state](format, &state_machine);
	}
	return (0);
}
