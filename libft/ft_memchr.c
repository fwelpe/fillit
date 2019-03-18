/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:52:53 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/22 19:52:56 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	char				cc;
	const char			*ss;

	ss = s;
	i = 0;
	cc = (char)c;
	ss = (const char *)s;
	while (i < n)
	{
		if (ss[i] == cc)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
