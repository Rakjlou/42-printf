/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:36:16 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:38:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# define FLAG_CHARACTER '%'
# define STATE_DEFAULT 0
# define STATE_END 1
# define STATE_FLAG 2

typedef struct	s_printf
{
	const char		*(*callback[1])(const char *, struct s_printf *);
	int				bytes_printed;
	unsigned int	state;

}	t_printf;

typedef struct s_printf_op
{
	int		alternative;
	int		padding;
	int		justified_left;
	int		blank;
	int		force_plus;
	int		precision;
	char	type;
}	t_printf_op;

int			ft_printf(const char *format, ...);
const char	*state_default(const char *format, t_printf *state_machine);
const char	*state_flag(const char *format, t_printf *state_machine);

#endif
