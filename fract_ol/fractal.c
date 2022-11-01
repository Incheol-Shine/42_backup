/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:19:38 by incshin           #+#    #+#             */
/*   Updated: 2022/11/02 05:44:36 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal(t_win *win, unsigned int (*set)(t_coord a, t_coord b))
{
	int	x;
	int	y;
	int	iteration;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			iteration = set(pixel_to_complex(x, y, &(win->cmp)), \
			win->cmp.c_base);
			if (iteration)
				my_mlx_pixel_put(&(win->img), x, y, set_color(iteration));
			x++;
		}
		y++;
	}
}

unsigned int	mandelbrot(t_coord c, t_coord a)
{
	t_coord	z;
	double	temp;
	int		num_iter;

	(void)a;
	z.re = 0;
	z.im = 0;
	num_iter = 0;
	while (num_iter < MAX_ITER)
	{
		if (z.re * z.re + z.im * z.im > 4)
			return (num_iter);
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		num_iter++;
	}
	return (0);
}

unsigned int	julia(t_coord z, t_coord c)
{
	double	temp;
	int		num_iter;

	num_iter = 0;
	while (num_iter < MAX_ITER)
	{
		if (z.re * z.re + z.im * z.im > 4)
			return (num_iter);
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		num_iter++;
	}
	return (0);
}

unsigned int	ship(t_coord c, t_coord a)
{
	t_coord	z;
	double	temp;
	int		num_iter;

	(void)a;
	z.re = 0;
	z.im = 0;
	num_iter = 0;
	while (num_iter < MAX_ITER)
	{
		if (z.re * z.re + z.im * z.im > 4)
			return (num_iter);
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = fabs(2 * z.re * z.im) + c.im;
		z.re = temp;
		num_iter++;
	}
	return (0);
}
