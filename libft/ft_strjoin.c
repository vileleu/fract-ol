/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:38:50 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 06:36:17 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*strj;
	unsigned int	len1;
	unsigned int	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strj = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(strj))
		return (NULL);
	ft_memmove(strj, s1, len1);
	ft_memmove(strj + len1, s2, len2);
	strj[len1 + len2] = '\0';
	free(s1);
	return (strj);
}
