/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:17:05 by vico              #+#    #+#             */
/*   Updated: 2021/09/24 17:43:17 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	syntax_arg(char *s, char *ss)
{
	if (ft_strcmp(s, "Julia") && ft_strcmp(s, "Mandelbrot"))
		return (0);
	if (!ft_strcmp(s, "Julia"))
	{
		if (!ss)
			return (1);
		if (ft_strlen(ss) > 1 || !ft_isdigit(ss[0]))
			return (1);
		if (ss[0] == '0' || ss[0] == '9')
			return (1);
	}
	return (2);
}

int	loop(char *title, t_mlx *mlx)
{
	mlx->init = mlx_init();
	if (!mlx->init)
		return (error_msg("mlx init failed"));
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, title);
	if (!mlx->win)
		return (error_msg("mlx window failed"));
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	if (!mlx->img)
		return (error_msg("mlx image failed"));
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->img_bits, \
	&mlx->img_size, &mlx->img_end);
	if (!mlx->img_addr)
		return (error_msg("mlx image addr failed"));
	find_pixel_color(mlx);
	mlx->img_default = mlx->img;
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	mlx_key_hook(mlx->win, keyboard_event, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_event, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, exit_event, mlx);
	mlx_loop(mlx->init);
	return (0);
}

void	norme_set_julia(t_mlx *mlx, int set)
{
	if (set == 5)
	{
		mlx->c_real_julia = -0.835;
		mlx->c_imaginary_julia = -0.2321;
	}
	else if (set == 6)
	{
		mlx->c_real_julia = -0.8;
		mlx->c_imaginary_julia = 0.156;
	}
	else if (set == 7)
	{
		mlx->c_real_julia = -0.7269;
		mlx->c_imaginary_julia = 0.1889;
	}
	else if (set == 8)
	{
		mlx->c_real_julia = 0;
		mlx->c_imaginary_julia = 0.8;
	}
}

void	set_julia(t_mlx *mlx, int set)
{
	if (set == 1)
	{
		mlx->c_real_julia = 0.285;
		mlx->c_imaginary_julia = 0;
	}
	else if (set == 2)
	{
		mlx->c_real_julia = 0.285;
		mlx->c_imaginary_julia = 0.01;
	}
	else if (set == 3)
	{
		mlx->c_real_julia = 0.45;
		mlx->c_imaginary_julia = 0.1428;
	}
	else if (set == 4)
	{
		mlx->c_real_julia = -0.70176;
		mlx->c_imaginary_julia = -0.3842;
	}
	norme_set_julia(mlx, set);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		ret;

	if (ac < 2 || ac > 3)
		return (error_msg("Need name of fractal in parameters \
(ex : ./fract-ol Mandelbrot)"));
	ret = syntax_arg(av[1], av[2]);
	if (!ret)
		return (error_msg("Bad syntax in parameters \
(ex : ./fract-ol Julia 1)"));
	else if (ret == 1)
		return (error_msg("Second parameter for Julia \
set must be a number between 1 and 8"));
	if (!ft_strcmp(av[1], "Julia"))
	{
		init_struct(&mlx, JULIA);
		set_julia(&mlx, ft_atoi(av[2]));
		return (loop(av[1], &mlx));
	}
	else
	{
		init_struct(&mlx, MANDELBROT);
		return (loop(av[1], &mlx));
	}
}
