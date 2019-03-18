/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:29:43 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/22 19:29:46 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;
	unsigned char	*ss;

	i = 0;
	cc = (unsigned char)c;
	ss = (unsigned char *)s;
	while (i < n)
	{
		ss[i] = cc;
		i++;
	}
	return (s);
}
