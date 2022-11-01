/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:19:30 by incshin           #+#    #+#             */
/*   Updated: 2022/11/02 05:26:22 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIN_WIDTH, WIN_HEIGHT, "fract'ol");
	win->img.img = mlx_new_image(win->mlx, WIN_WIDTH, WIN_HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel, \
	&win->img.line_length, &win->img.endian);
	win->cmp.c_x = 0;
	win->cmp.c_y = 0;
	win->cmp.zoom = WIN_WIDTH / 4;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_coord	pixel_to_complex(int x, int y, t_complex *cmp)
{
	t_coord	c;

	c.re = x / cmp->zoom - WIN_WIDTH / (2 * cmp->zoom) + (cmp->c_x);
	c.im = -y / cmp->zoom + WIN_HEIGHT / (2 * cmp->zoom) + (cmp->c_y);
	return (c);
}

unsigned int	set_color(int iter)
{
	float	release_rate;

	release_rate = (float)iter / (float)(MAX_ITER);
	return ((1 << 24) * (1 - release_rate));
}

void	error_msg(void)
{
	printf("usage : fractol [mandelbrot julia ship]\n");
	exit(0);
}
