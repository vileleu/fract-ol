/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:55:35 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 06:19:29 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*newlist;

	if (!lst || !f)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	newlist = begin;
	lst = lst->next;
	while (lst != NULL)
	{
		newlist->next = ft_lstnew(f(lst->content));
		if (!(newlist->next))
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		lst = lst->next;
		newlist = newlist->next;
	}
	return (begin);
}
