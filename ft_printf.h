/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:36:16 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/28 03:14:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define CONVERSION_CHARACTER '%'
# define FLAGS " +-0#"
# define CONV_SPECIFIERS "cspdiuxX%"
# define STATE_DEFAULT 0
# define STATE_CONVERSION_FLAGS 1
# define STATE_CONVERSION_LENGTH 2
# define STATE_CONVERSION_PRECISION 3
# define STATE_CONVERSION_PRINT 4
# define STATE_WRONG_FLAG 5
# define STATE_END 6

# ifdef __APPLE__
#  define NULLSTR_PLACEHOLDER "0x0"
# else
#  define NULLSTR_PLACEHOLDER "(null)"
# endif

/* POINTEUR NULL (nil) linux 0x0 mac */

typedef struct s_printf_op
{
	t_bool		alternative;
	t_bool		zero_padded;
	t_bool		justified_left;
	t_bool		blank;
	t_bool		force_plus;
	t_bool		precision;
	t_bool		length;
	int			precision_value;
	int			length_value;
	char		type;
	const char	*start;
}	t_printf_op;

typedef struct s_printf
{
	const char		*(*callback[5])(const char *, struct s_printf *);
	va_list			args;
	int				bytes_printed;
	unsigned int	current;
	t_printf_op		op;

}	t_printf;

int			ft_printf(const char *format, ...);
const char	*state_default(const char *format, t_printf *state);
const char	*state_conversion(const char *format, t_printf *state);
const char	*state_conversion_flags(const char *format, t_printf *state);
const char	*state_conversion_length(const char *format, t_printf *state);
const char	*state_conversion_precision(const char *format, t_printf *state);
const char	*state_conversion_print(const char *format, t_printf *state);
void		print_character(t_printf *state);
void		print_string(t_printf *state);
void		print_pointer(t_printf *state);
void		print_int(t_printf *state);
void		print_unsigned_int(t_printf *state);
void		print_hex_lowercase(t_printf *state);
void		print_hex_uppercase(t_printf *state);
void		print_flag(t_printf *state);

/* REMOVE ME OR ELSE */
void		print_op_debug(t_printf_op *op);
void		print_state(t_printf *state);

#endif
