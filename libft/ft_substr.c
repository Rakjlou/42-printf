/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:48:15 by nsierra-          #+#    #+#             */
/*   Updated: 2021/11/27 03:48:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	ssize;

	ssize = ft_strlen(s);
	if (start >= ssize)
		return (ft_calloc(1, 1));
	s = s + start;
	len = ft_min(len, ft_strlen(s));
	res = ft_calloc(1, len + 1);
	if (res == NULL)
		return (NULL);
	return ((char *)ft_memcpy(res, s, len));
}
