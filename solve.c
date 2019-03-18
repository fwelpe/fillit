/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:01:49 by rberon-s          #+#    #+#             */
/*   Updated: 2019/01/27 13:38:21 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count(t_tetr *t)
{
	t_tetr	*c;
	int		i;

	c = t;
	i = 0;
	while (c)
	{
		c = c->next;
		i++;
	}
	return (i);
}

int		check(t_tetr *t)
{
	t_tetr	*c;
	int		i;
	int		j;

	if (!t || !(t->prev))
		return (1);
	c = t->prev;
	while (c)
	{
		i = -1;
		while (i++ < 3)
		{
			j = -1;
			while (j++ < 3)
				if (t->x[i] == c->x[j] && t->y[i] == c->y[j])
					return (0);
		}
		c = c->prev;
	}
	return (1);
}

int		move(t_tetr *t, int n)
{
	int i;
	int a;

	i = 0;
	FALSECHECK(t);
	while (i < 4)
		if (t->x[i++] > n - 2)
			i = 5;
	if (i == 4)
		while (i-- > 0)
			(t->x[i])++;
	else
	{
		i = 0;
		while (i < 4)
			if (t->y[i++] > n - 2)
				return (0);
		a = ft_minf(t->x[0], t->x[1], t->x[2], t->x[3]);
		while (i-- > 0)
		{
			t->x[i] -= a;
			(t->y[i])++;
		}
	}
	return (1);
}

t_tetr	*place_iter(t_tetr *t, int n, int *r)
{
	t_tetr	*c;

	c = t;
	AUTOYES(t, *r);
	while (!check(c))
	{
		if (!move(c, n))
		{
			goup(c);
			AUTONO(c->prev, *r);
			while (!move(c->prev, n))
			{
				goup(c->prev);
				c = c->prev;
				AUTONO(c->prev, *r);
			}
			if (!check(c->prev))
				return (c->prev);
			else
				return (c);
		}
	}
	return (c->next);
}

int		place(t_tetr *t, int n)
{
	int		r;

	r = 2;
	while (1)
	{
		if (r == 1 || r == 0)
			return (r);
		t = place_iter(t, n, &r);
	}
}
