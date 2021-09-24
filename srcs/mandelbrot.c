/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:02:17 by vico              #+#    #+#             */
/*   Updated: 2021/09/24 17:48:59 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	norme_put_mandelbrot(t_mlx *mlx, t_iterate *ite, float n)
{
	int	bright;

	bright = 0;
	bright = 255 * (n / 100);
	if (n == 100)
		bright = 0;
	(mlx->img_addr)[(ite->pixel)++] = bright;
	(mlx->img_addr)[(ite->pixel)++] = bright;
	(mlx->img_addr)[(ite->pixel)++] = bright;
	(mlx->img_addr)[(ite->pixel)++] = 0;
}

void	put_mandelbrot(t_mlx *mlx, t_iterate *ite, float aa, float bb)
{
	float	a;
	float	b;
	float	ca;
	float	cb;
	float	n;

	a = find_pixel_location_a(ite->x, WIDTH, mlx->min_x, mlx->max_x);
	b = find_pixel_location_b(ite->y, HEIGHT, mlx->min_y, mlx->max_y);
	ca = a;
	cb = b;
	n = 0;
	while (n < 100)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + ca;
		b = bb + cb;
		if (abs_float(a, b) > 16)
			break ;
		n++;
	}
	norme_put_mandelbrot(mlx, ite, n);
}
