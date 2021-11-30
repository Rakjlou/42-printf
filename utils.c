/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:22:23 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/30 15:24:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	cat_padding(t_printf *state, char *str, int padding_size)
{
	char	padding_character;

	if (state->op.zero_padded == TRUE && state->op.justified_left == FALSE)
		padding_character = '0';
	else
		padding_character = ' ';
	while (*str)
		str++;
	while (padding_size-- > 0)
		*str++ = padding_character;
}

char	*apply_length_flag(t_printf *state, char *original)
{
	size_t	original_size;
	char	*flagged;
	int		padding_size;
	int		i;

	original_size = ft_strlen(original);
	if (state->op.length == FALSE || state->op.length_value <= original_size)
		return (original);
	i = 0;
	padding_size = state->op.length_value - original_size;
	flagged = ft_calloc(state->op.length_value + 1, sizeof(char));
	if (flagged == NULL)
		return (original);
	if (*original == '+' || *original == '-')
		flagged[i++] = *original;
	if (state->op.justified_left == TRUE)
		ft_strlcat(flagged, original + i, state->op.length_value + 1);
	cat_padding(state, flagged, padding_size);
	if (state->op.justified_left == FALSE)
		ft_strlcat(flagged, original + i, state->op.length_value + 1);
	free(original);
	return (flagged);
}

char	*apply_sharp_flag(t_printf *state, char *original, char *prefix)
{
	char	*flagged;

	if (state->op.alternative == FALSE
		|| ft_strncmp(original, "0", ft_strlen(original)) == 0)
		return (original);
	flagged = ft_strjoin(prefix, original);
	if (flagged == NULL)
		return (original);
	free(original);
	return (flagged);
}
