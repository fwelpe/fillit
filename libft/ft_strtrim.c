/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:43:50 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/30 16:43:51 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*c;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (s[ft_strlen(s) - j - 1] == ' ' ||
		s[ft_strlen(s) - j - 1] == '\n' || s[ft_strlen(s) - j - 1] == '\t')
			j++;
		if (i == ft_strlen(s))
			j = 0;
		if ((c = ft_strnew(ft_strlen(s) - i - j)))
		{
			c = ft_strncpy(c, s + i, ft_strlen(s) - i - j);
			return (c);
		}
	}
	return (NULL);
}
