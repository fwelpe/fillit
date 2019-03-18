/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:19:25 by rberon-s          #+#    #+#             */
/*   Updated: 2018/12/07 16:19:27 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*s;

	if (!ptr)
	{
		if (!(ft_memalloc(size)))
			return (NULL);
		return (ft_memalloc(size));
	}
	if (!size)
	{
		if (!(s = (char *)ft_memalloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (s);
	}
	if (!(s = (char *)ft_memalloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(s, ptr, size);
		ft_memdel(&ptr);
	}
	return (s);
}
