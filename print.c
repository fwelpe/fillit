/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:02:00 by rberon-s          #+#    #+#             */
/*   Updated: 2019/01/20 17:34:07 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printmap(t_tetr *tetr, int n, char s[n + 1][n])
{
	int		i;
	int		j;
	t_tetr	*t;
	char	c;

	c = 'A';
	t = tetr;
	while (t)
	{
		i = -1;
		while (i++ < 3)
			s[t->x[i]][t->y[i]] = c;
		t = t->next;
		c++;
	}
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (j++ < n)
			ft_putchar(s[j][i]);
	}
}

void	makemap(t_tetr *tetr, int n)
{
	char	s[n + 1][n];
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (j++ < n)
			s[j][i] = '.';
		s[n][i] = '\n';
	}
	printmap(tetr, n, s);
}
