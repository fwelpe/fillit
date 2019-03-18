/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:44:14 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/30 16:44:15 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*c;
	int		k;
	int		i;
	int		j;
	int		m;

	m = n;
	i = ft_size(n);
	j = 0;
	k = (n < 0 ? 1 : 0);
	if (!(c = ft_strnew(k + i)))
		return (NULL);
	while (((j < k + i) && (n >= 0)) || (j < k + i - 1))
	{
		c[k + i - j - 1] = (n > 0 ? ((n % 10) + '0') : ('0' - (n % 10)));
		n /= 10;
		j++;
	}
	c[0] = (m < 0 ? '-' : c[0]);
	return (c);
}
