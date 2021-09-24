/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:36:36 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 06:19:46 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!(lst))
		return (NULL);
	lst->content = (void *)content;
	lst->next = NULL;
	return (lst);
}
