/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:10:19 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:38:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

const char	*state_flag(const char *format, t_printf *state_machine)
{
	t_printf_op	op;

	ft_bzero(&op, sizeof(t_printf_op));
	(void)state_machine;
	return (format);
}
