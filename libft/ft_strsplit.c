/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:43:59 by rberon-s          #+#    #+#             */
/*   Updated: 2018/11/30 16:44:00 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *s, char c)
{
	size_t		k;
	size_t		j;

	k = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c && (s[j + 1] == '\0' || s[j + 1] == c))
			k++;
		j++;
	}
	return (k);
}

static char		*ft_word(const char *str, char c, int *i)
{
	char		*s;
	int			k;

	if (!(s = (char *)ft_strnew(sizeof(char) * (ft_strlen(str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(const char *str, char c)
{
	int			i;
	int			j;
	char		**s;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	if (!(s = (char **)ft_strnew(sizeof(char *) * ft_count_words(str, c))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < ft_count_words(str, c) && str[i])
	{
		s[j] = ft_word(str, c, &i);
		j++;
	}
	s[j] = NULL;
	return (s);
}
