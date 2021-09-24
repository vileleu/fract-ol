/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:27:50 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 06:20:07 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*sbis;

	i = 0;
	sbis = (unsigned char *)s;
	while (i < n)
	{
		if (sbis[i] == (unsigned char)c)
			return (&sbis[i]);
		i++;
	}
	return (NULL);
}
