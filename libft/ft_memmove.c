/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:50:34 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/22 19:50:36 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	i = -1;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (src >= dst)
	{
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		while (++i < len)
			d[len - 1 - i] = s[len - 1 - i];
	}
	return (dst);
}
