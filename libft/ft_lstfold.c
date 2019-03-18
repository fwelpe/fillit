/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:22:09 by rberon-s          #+#    #+#             */
/*   Updated: 2018/12/05 13:22:11 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list *lst, void *(*f)(const void *, const void*, size_t))
{
	void	*result;

	if (lst && f)
	{
		result = lst->content;
		lst = lst->next;
		while (lst != NULL)
		{
			result = (*f)(result, lst->content, lst->content_size);
			lst = lst->next;
		}
		return (result);
	}
	return (NULL);
}
