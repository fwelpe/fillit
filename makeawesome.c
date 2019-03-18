/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeawesome.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:29:46 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/01/27 12:17:20 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	goup(t_tetr *t)
{
	int		i;
	int		a;
	int		b;

	i = -1;
	a = ft_minf(t->x[0], t->x[1], t->x[2], t->x[3]);
	b = ft_minf(t->y[0], t->y[1], t->y[2], t->y[3]);
	while (++i < 4)
	{
		t->x[i] -= a;
		t->y[i] -= b;
	}
}

t_tetr	*goup_all(t_tetr *s)
{
	t_tetr	*iter;

	if (!s)
		return (NULL);
	iter = s;
	while (iter)
	{
		goup(iter);
		iter = iter->next;
	}
	return (s);
}

int		cell_exist(t_tetr *t, int x, int y)
{
	int	i;
	int a;

	i = 0;
	a = 0;
	while (i <= 3)
	{
		if (t->x[i] == x && t->y[i] == y)
			a++;
		i++;
	}
	return (a);
}

int		neighbour_count(t_tetr *t, int x, int y)
{
	int a;

	a = 0;
	if (x > 0)
		a += cell_exist(t, x - 1, y);
	if (x < 3)
		a += cell_exist(t, x + 1, y);
	if (y > 0)
		a += cell_exist(t, x, y - 1);
	if (y < 3)
		a += cell_exist(t, x, y + 1);
	return (a);
}

t_tetr	*validate(t_tetr *t)
{
	int		xyiter;
	t_tetr	*beginning;
	int		a;

	if (!t)
		return (NULL);
	beginning = t;
	while (t)
	{
		a = 0;
		xyiter = 0;
		while (xyiter <= 3)
		{
			a += neighbour_count(t, t->x[xyiter], t->y[xyiter]);
			xyiter++;
		}
		if (a < 6)
			return (NULL);
		t = t->next;
	}
	return (beginning);
}
