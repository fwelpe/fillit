/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:43:37 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/30 16:43:37 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *c;

	if (s1 && s2)
	{
		if ((c = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			c = ft_strcat(c, s1);
			return (ft_strcat(c, s2));
		}
	}
	return (NULL);
}
