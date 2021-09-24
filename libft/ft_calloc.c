/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:31:40 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 06:15:15 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	tab = malloc(size * count);
	if (!(tab))
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}
