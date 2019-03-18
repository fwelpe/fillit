/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:03:29 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/22 21:03:30 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t d;
	size_t s;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (!size)
		return (s);
	while (src[i] && ((d + i + 1) < (size)))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	if (size > d)
		return (d + s);
	return (size + s);
}
