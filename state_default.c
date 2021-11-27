/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:08:59 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/27 02:08:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>

static int	get_state(const char token)
{
	if (token == FLAG_CHARACTER)
		return (STATE_FLAG);
	else if (token == '\0')
		return (STATE_END);
	return (STATE_DEFAULT);
}

const char	*state_default(const char *format, t_printf *state_machine)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != FLAG_CHARACTER)
		i++;
	if (i != 0)
	{
		write(STDOUT_FILENO, format, i);
		state_machine->bytes_printed += i;
	}
	state_machine->state = get_state(format[i]);
	return (format + i);
}
