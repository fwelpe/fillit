/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:49:19 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/01/26 14:44:23 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*ft_tldel(t_tetr *t1, char **line)
{
	t_tetr	*t2;

	while (t1)
	{
		t2 = t1->next;
		FREE_N_NULL(t1);
		t1 = t2;
	}
	if (line && *line)
	{
		FREE_N_NULL(*line);
	}
	return (NULL);
}

int			read_tetramino(t_tetr *iter, int fd, int x, char **line)
{
	int	cell_num;
	int	y;

	y = -1;
	cell_num = -1;
	while (++y < 4)
	{
		if (get_next_line(fd, line) < 1 || ft_strlen(*line) != 5 || CH(line))
			return (0);
		while (++x < 4)
		{
			if ((*line)[x] == '#')
			{
				if (++cell_num > 3)
					return (0);
				iter->x[cell_num] = x;
				iter->y[cell_num] = y;
			}
			else if ((*line)[x] != '.')
				return (0);
		}
		FREE_N_NULL(*line);
		x = -1;
	}
	return (cell_num == 3 ? 1 : 0);
}

t_tetr		*rf_aux(t_tetr *result, int fd, char **line)
{
	t_tetr	*iter;
	t_tetr	*prev;

	iter = result;
	while (1)
	{
		if (!read_tetramino(iter, fd, -1, line))
			return (ft_tldel(result, line));
		if (!get_next_line(fd, line))
			break ;
		if (ft_strlen(*line) != 1 || *line[0] != '\n')
			return (ft_tldel(result, line));
		prev = iter;
		iter->next = (t_tetr*)malloc(sizeof(*iter));
		iter = iter->next;
		iter->next = NULL;
		iter->prev = prev;
		FREE_N_NULL(*line);
	}
	return (count(result) <= 26 ? result : NULL);
}

t_tetr		*read_file(char *filename)
{
	int		fd;
	t_tetr	*result;
	char	*line;

	line = NULL;
	result = (t_tetr*)malloc(sizeof(*result));
	result->prev = NULL;
	result->next = NULL;
	fd = open(filename, O_RDONLY);
	return (validate(goup_all(rf_aux(result, fd, &line))));
}
