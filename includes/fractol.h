/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:17:56 by vico              #+#    #+#             */
/*   Updated: 2021/09/24 17:49:41 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 500
# define HEIGHT 500
# define MANDELBROT 1
# define JULIA 2
# define MAX_X 2
# define MIN_X -2
# define MAX_Y 2
# define MIN_Y -2
# define SPEED 0.1
# define ZOOM 0.1
# define MAX_ZOOM 0.000001

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	void	*img_default;
	int		check_default;
	char	*img_addr;
	int		img_bits;
	int		img_size;
	int		img_end;
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
	int		set;
	float	c_real_julia;
	float	c_imaginary_julia;
}				t_mlx;

typedef struct s_iterate
{
	int	x;
	int	y;
	int	pixel;
}				t_iterate;

/*
**	MLX
*/

void	find_pixel_color(t_mlx *mlx);

/*
**	SET
*/

float	find_pixel_location_a(int x, int size, float min, float max);
float	find_pixel_location_b(int y, int size, float min, float max);

void	put_mandelbrot(t_mlx *mlx, t_iterate *ite, float aa, float bb);
void	put_julia(t_mlx *mlx, t_iterate *ite, float aa, float bb);

/*
**	EVENTS
*/

int		keyboard_event(int key, void *data);
int		mouse_event(int key, int x, int y, t_mlx *mlx);
int		exit_event(void *data);

/*
**	ERRORS
*/

int		error_msg(char *s);
int		exit_msg(char *s);

/*
**	UTILS
*/

void	init_struct(t_mlx *a, int set);
void	refresh_image(t_mlx *mlx);
float	abs_float(float a, float b);

#endif
