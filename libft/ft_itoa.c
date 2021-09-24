/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:40:52 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 06:18:49 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countchar(int n)
{
	int				count;
	unsigned int	nb;

	count = 1;
	if (n < 0)
	{
		count++;
		nb = (unsigned int) -n;
	}
	else
		nb = (unsigned int)n;
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*tab;
	unsigned int	nb;

	i = countchar(n);
	tab = malloc(sizeof(char) * (i + 1));
	if (!(tab))
		return (NULL);
	if (n < 0)
	{
		nb = (unsigned int) -n;
		tab[0] = '-';
	}
	else
		nb = (unsigned int)n;
	tab[i] = '\0';
	while (--i >= 0)
	{
		tab[i] = nb % 10 + 48;
		nb = nb / 10;
		if (nb == 0)
			break ;
	}
	return (tab);
}
