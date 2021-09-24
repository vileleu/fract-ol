/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:01:54 by vico              #+#    #+#             */
/*   Updated: 2021/09/24 17:40:54 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	find_pixel_location_a(int x, int size, float min, float max)
{
	float	tmp;
	float	ret;

	tmp = (max - min) / size;
	ret = min + x * tmp;
	return (ret);
}

float	find_pixel_location_b(int y, int size, float min, float max)
{
	float	tmp;
	float	ret;

	tmp = (max - min) / size;
	ret = max - y * tmp;
	return (ret);
}

void	find_pixel_color(t_mlx *mlx)
{
	t_iterate	ite;

	ite.pixel = 0;
	ite.y = 0;
	while (ite.y < HEIGHT)
	{
		ite.x = 0;
		while (ite.x < WIDTH)
		{
			if (mlx->set == JULIA)
				put_julia(mlx, &ite, 0, 0);
			else if (mlx->set == MANDELBROT)
				put_mandelbrot(mlx, &ite, 0, 0);
			(ite.x)++;
		}
		(ite.y)++;
	}
}
