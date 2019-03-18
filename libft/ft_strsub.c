/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:43:27 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/30 16:43:27 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *c;

	if (s)
	{
		if ((c = (char *)malloc(len + 1)))
		{
			c = ft_strncpy(c, (char *)s + start, len);
			c[len] = '\0';
			return (c);
		}
	}
	return (NULL);
}
