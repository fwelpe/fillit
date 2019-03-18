/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:15:10 by rberon-s          #+#    #+#             */
/*   Updated: 2018/12/02 12:15:11 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *a;

	if (!(a = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		a->content = NULL;
		a->content_size = 0;
	}
	else
	{
		if (!(a->content = ft_memalloc(content_size)))
			return (NULL);
		a->content = ft_memcpy(a->content, content, content_size);
		a->content_size = (content ? content_size : 0);
	}
	a->next = NULL;
	return (a);
}
