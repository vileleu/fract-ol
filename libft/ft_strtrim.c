/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:02:38 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 06:38:12 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;
	char	*news;

	i = 0;
	size = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (charset(set, s1[i]) == 1)
		i++;
	while (charset(set, s1[j]) == 1)
		j--;
	if (i > j)
		return (ft_strdup(""));
	news = malloc(sizeof(char) * (j - i + 2));
	if (!(news))
		return (NULL);
	while (i <= j && s1)
		news[size++] = s1[i++];
	news[size] = '\0';
	return (news);
}
