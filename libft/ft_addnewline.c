/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnewline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:04:19 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/01/26 13:50:26 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_addnewline(char **line)
{
	char	*tmp;

	tmp = ft_strjoin(*line, "\n");
	free(*line);
	*line = tmp;
	return (1);
}
