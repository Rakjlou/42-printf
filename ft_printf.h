/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:36:16 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/27 21:42:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define CONVERSION_CHARACTER '%'
# define FLAGS " .+-0#"
# define CONV_SPECIFIERS "cspdiuxX%"
# define STATE_DEFAULT 0
# define STATE_FLAG 1
# define STATE_END 2

# ifdef __APPLE__
#  define NULLSTR_PLACEHOLDER "0x0"
# else
#  define NULLSTR_PLACEHOLDER "(null)"
# endif

/* POINTEUR NULL (nil) linux 0x0 mac */

typedef struct	s_printf
{
	const char		*(*callback[2])(const char *, struct s_printf *);
	va_list			args;
	int				bytes_printed;
	unsigned int	current;

}	t_printf;

typedef struct s_printf_op
{
	t_bool	alternative;
	t_bool	padding;
	t_bool	justified_left;
	t_bool	blank;
	t_bool	force_plus;
	t_bool	precision;
	int		precision_value;
	char	type;
}	t_printf_op;

int			ft_printf(const char *format, ...);
const char	*state_default(const char *format, t_printf *state);
const char	*state_flag(const char *format, t_printf *state);
void		print_character(t_printf_op *op, t_printf *state);
void		print_string(t_printf_op *op, t_printf *state);
void		print_pointer(t_printf_op *op, t_printf *state);
void		print_int(t_printf_op *op, t_printf *state);
void		print_unsigned_int(t_printf_op *op, t_printf *state);
void		print_hex_lowercase(t_printf_op *op, t_printf *state);
void		print_hex_uppercase(t_printf_op *op, t_printf *state);
void		print_flag(t_printf_op *op, t_printf *state);

#endif
