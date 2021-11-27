/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_conversion_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:11:04 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/27 22:23:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*state_conversion_length(const char *format, t_printf *state)
{
	state->current = STATE_CONVERSION_PRECISION;
	return (format);
}
