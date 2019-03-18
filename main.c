/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:01:16 by rberon-s          #+#    #+#             */
/*   Updated: 2019/01/26 14:30:07 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		lfix(t_tetr *t)
{
	int i;

	i = 0;
	while (t)
	{
		i = ft_max(i, ft_maxf(t->x[0], t->x[1], t->x[2], t->x[3]));
		i = ft_max(i, ft_maxf(t->y[0], t->y[1], t->y[2], t->y[3]));
		if (i > 2)
			break ;
		t = t->next;
	}
	return (i + 1);
}

int		main(int argc, char **argv)
{
	int		n;
	t_tetr	*t;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	t = read_file(argv[1]);
	if (!t)
	{
		ft_putstr("error\n");
		return (1);
	}
	n = ft_max(lfix(t), ft_sqrtm(4 * count(t)));
	while (!place(t, n))
		n++;
	makemap(t, n);
	ft_tldel(t, NULL);
	return (0);
}
