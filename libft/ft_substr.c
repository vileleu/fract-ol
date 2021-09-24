/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:15:49 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 06:38:31 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*news;

	if (s == NULL)
		return (NULL);
	i = 0;
	news = malloc(sizeof(char) * (len + 1));
	if (!(news))
		return (NULL);
	if (start > ft_strlen(s))
	{
		news[0] = '\0';
		return (news);
	}
	while (s[i + start] != '\0' && i < len)
	{
		news[i] = s[i + start];
		i++;
	}
	news[i] = '\0';
	return (news);
}
