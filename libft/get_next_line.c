/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:55:17 by vileleu           #+#    #+#             */
/*   Updated: 2021/09/02 07:08:47 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cutstr(t_liste *lst, char **line, int i, char *temp)
{
	while (lst->str[i] != '\0')
	{
		if (lst->str[i] == '\n')
		{
			line = ft_strjoin_gnl(line, lst->str, i);
			temp = ft_strdup_gnl(lst->str + i + 1);
			if (!(line) || !(temp))
				return (-1);
			free(lst->str);
			lst->str = ft_strdup_gnl(temp);
			if (!(lst->str))
				return (-1);
			free(temp);
			return (1);
		}
		i++;
	}
	line = ft_strjoin_gnl(line, lst->str, i);
	if (!(line))
		return (-1);
	free(lst->str);
	lst->str = NULL;
	return (0);
}

int	finish(t_liste **begin)
{
	t_liste	*tmp;

	tmp = *begin;
	while (*begin != NULL)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		if (tmp->str != NULL)
			free(tmp->str);
		free(tmp);
	}
	return (-1);
}

int	rdfile(char *str, int fd)
{
	int	rd;

	rd = read(fd, str, BUFFER_SIZE);
	if (rd > 0)
		str[rd] = '\0';
	return (rd);
}

int	norme(t_liste *lst, char **line, int *rd)
{
	*rd = cutstr(lst, line, 0, NULL);
	if (*rd == -1)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				rd;
	char			str[BUFFER_SIZE + 1];
	static t_liste	*begin;
	t_liste			*lst;

	lst = findfd(&begin, fd);
	if (!line || read(fd, str, 0) < 0 || !(lst))
		return (finish(&begin));
	line[0] = ft_strdup_gnl("");
	rd = 0;
	while (rd != 1)
	{
		if (lst->str == NULL)
		{
			rd = rdfile(str, fd);
			if (rd == 0)
				return (free_fd(&begin, fd));
			lst->str = ft_strdup_gnl(str);
			if (rd == -1 || !(lst->str))
				return (finish(&begin));
		}
		if (!(norme(lst, line, &rd)))
			return (finish(&begin));
	}
	return (1);
}
