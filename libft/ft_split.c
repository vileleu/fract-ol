/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:39:48 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 19:58:59 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	countwords(const char *str, char c)
{
	unsigned int	nb;
	unsigned int	i;

	nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			nb++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static unsigned int	sizeword(const char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char	**free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	*ft_split_loop(char const *s, int *size, char c)
{
	char	*news;
	int		j;

	j = 0;
	while (s[*size] && s[*size] == c)
		(*size)++;
	news = malloc(sizeof(char) * (sizeword(s + *size, c) + 1));
	if (!(news))
		return (NULL);
	while (s[*size] && s[*size] != c)
		news[j++] = s[(*size)++];
	news[j] = '\0';
	return (news);
}

char	**ft_split(char const *s, char c)
{
	char			**news;
	unsigned int	i;
	int				size;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	news = malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!(news))
		return (NULL);
	while (i < countwords(s, c))
	{
		news[i] = ft_split_loop(s, &size, c);
		if (!(news[i]))
			return (free_tab(news, i - 1));
		i++;
	}
	news[i] = NULL;
	return (news);
}
