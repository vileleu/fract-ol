/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:24:15 by vico              #+#    #+#             */
/*   Updated: 2021/09/24 17:41:03 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	norme_keyboard_event(int key, t_mlx *mlx, float tmp)
{
	if (key == 65363)
	{
		tmp = (mlx->max_x - mlx->min_x) * SPEED;
		mlx->min_x += tmp;
		mlx->max_x += tmp;
		refresh_image(mlx);
	}
	else if (key == 65362)
	{
		tmp = (mlx->max_y - mlx->min_y) * SPEED;
		mlx->min_y += tmp;
		mlx->max_y += tmp;
		refresh_image(mlx);
	}
	else if (key == 32)
	{
		mlx_destroy_image(mlx->init, mlx->img);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img_default, 0, 0);
		mlx->check_default = 1;
		mlx->min_x = MIN_X;
		mlx->max_x = MAX_X;
		mlx->min_y = MIN_Y;
		mlx->max_y = MAX_Y;
	}
	return (0);
}

int	keyboard_event(int key, void *data)
{
	t_mlx	*mlx;
	float	tmp;

	mlx = (t_mlx *)data;
	if (key == 65361)
	{
		tmp = (mlx->max_x - mlx->min_x) * SPEED;
		mlx->min_x -= tmp;
		mlx->max_x -= tmp;
		refresh_image(mlx);
	}
	else if (key == 65364)
	{
		tmp = (mlx->max_y - mlx->min_y) * SPEED;
		mlx->min_y -= tmp;
		mlx->max_y -= tmp;
		refresh_image(mlx);
	}
	else if (key == 65307)
		exit(EXIT_SUCCESS);
	return (norme_keyboard_event(key, mlx, 0));
}

void	norme_mouse_event(t_mlx *mlx)
{
	float	tmp;

	tmp = (mlx->max_x - mlx->min_x) * ZOOM;
	mlx->min_x -= tmp;
	mlx->max_x += tmp;
	tmp = (mlx->max_y - mlx->min_y) * ZOOM;
	mlx->min_y -= tmp;
	mlx->max_y += tmp;
}

int	mouse_event(int key, int x, int y, t_mlx *mlx)
{
	float	tmp;

	(void)x;
	(void)y;
	if (key == 4)
	{
		if (mlx->max_x - mlx->min_x > MAX_ZOOM || \
		mlx->max_y - mlx->min_y > MAX_ZOOM)
		{
			tmp = (mlx->max_x - mlx->min_x) * ZOOM;
			mlx->min_x += tmp;
			mlx->max_x -= tmp;
			tmp = (mlx->max_y - mlx->min_y) * ZOOM;
			mlx->min_y += tmp;
			mlx->max_y -= tmp;
			refresh_image(mlx);
		}
	}
	else if (key == 5)
	{
		norme_mouse_event(mlx);
		refresh_image(mlx);
	}
	return (0);
}

int	exit_event(void *data)
{
	keyboard_event(65307, data);
	return (0);
}
