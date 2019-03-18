/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:42:49 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/30 16:42:50 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	int		i;

	i = 0;
	if (s && f)
	{
		if (!(c = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		while (s[i])
		{
			c[i] = f(i, s[i]);
			i++;
		}
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}
