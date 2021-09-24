/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:41:16 by vico              #+#    #+#             */
/*   Updated: 2021/09/24 18:00:12 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_mlx *a, int set)
{
	a->init = NULL;
	a->win = NULL;
	a->img = NULL;
	a->img_default = NULL;
	a->check_default = 1;
	a->img_addr = NULL;
	a->img_bits = 0;
	a->img_end = 0;
	a->img_size = 0;
	a->min_x = MIN_X;
	a->max_x = MAX_X;
	a->min_y = MIN_Y;
	a->max_y = MAX_Y;
	a->set = set;
	a->c_real_julia = 0;
	a->c_imaginary_julia = 0;
}

void	refresh_image(t_mlx *mlx)
{
	if (mlx->check_default)
		mlx->check_default = 0;
	else
		mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = NULL;
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	if (!mlx->img)
		exit_msg("mlx image failed");
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->img_bits, \
	&mlx->img_size, &mlx->img_end);
	if (!mlx->img_addr)
		exit_msg("mlx image addr failed");
	find_pixel_color(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}

float	abs_float(float a, float b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}
