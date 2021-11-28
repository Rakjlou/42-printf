/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_debug_REMOVE_ME.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:49:05 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/28 06:55:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_op_debug(t_printf_op *op)
{
	puts("[");
	printf("\ttype: >%c<\n", op->type);
	printf("\talternative: %d\n", op->alternative);
	printf("\tzero padded: %d\n", op->zero_padded);
	printf("\tjustified_left: %d\n", op->justified_left);
	printf("\tblank: %d\n", op->blank);
	printf("\tforce_plus: %d\n", op->force_plus);
	printf("\tprecision: %d\n", op->precision);
	printf("\tlength: %d\n", op->length);
	printf("\tprecision_value: %d\n", op->precision_value);
	printf("\tlength_value: %d\n", op->length_value);
	printf("\tstart: >%s<\n", op->start);
	puts("]");
}

void	print_state(t_printf *state)
{
	puts("\n-----------------------------------");
	printf("Current state: %d\n", state->current);
	printf("Bytes printed: %u\n", state->bytes_printed);
	print_op_debug(&state->op);
	puts("\n-----------------------------------");
}
