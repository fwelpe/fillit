/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:47:09 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/21 19:03:29 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	chit(unsigned long long n)
{
	if (n > 1)
		return (9223372036854775807);
	return (9223372036854775807);
}

int							ft_atoi(const char *s)
{
	int						i;
	unsigned long long		n;
	int						sn;

	sn = 1;
	i = 0;
	n = 0;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sn = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if ((sn > 0) && (n > (unsigned long long)(chit(n) - s[i] + '0') / 10))
			return (-1);
		if ((sn < 0) && (n > (9223372036854775808U - s[i] + '0') / 10))
			return (0);
		n = n * 10 + s[i] - '0';
		i++;
	}
	return ((int)(n * sn));
}
