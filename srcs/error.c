/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:43:10 by vico              #+#    #+#             */
/*   Updated: 2021/09/24 17:40:59 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_msg(char *s)
{
	ft_putstr_fd("ERROR : ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	exit_msg(char *s)
{
	ft_putstr_fd("ERROR : ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
	return (0);
}
