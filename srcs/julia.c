/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:02:52 by vico              #+#    #+#             */
/*   Updated: 2021/09/24 17:41:05 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	norme_put_julia(t_mlx *mlx, t_iterate *ite, float n)
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

void	put_julia(t_mlx *mlx, t_iterate *ite, float aa, float bb)
{
	float	a;
	float	b;
	float	twoab;
	float	n;

	a = find_pixel_location_a(ite->x, WIDTH, mlx->min_x, mlx->max_x);
	b = find_pixel_location_b(ite->y, HEIGHT, mlx->min_y, mlx->max_y);
	n = 0;
	while (n < 100)
	{
		aa = a * a;
		bb = b * b;
		twoab = 2 * a * b;
		a = aa - bb + mlx->c_real_julia;
		b = twoab + mlx->c_imaginary_julia;
		if (aa + bb > 16)
			break ;
		n++;
	}
	norme_put_julia(mlx, ite, n);
}
