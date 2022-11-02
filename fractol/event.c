/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:19:34 by incshin           #+#    #+#             */
/*   Updated: 2022/11/02 13:55:30 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(win->mlx, win->win);
		mlx_destroy_image(win->mlx, win->img.img);
		exit(0);
	}
	return (0);
}

int	mouse_zoom(int btn, int x, int y, t_win *win)
{
	t_coord	c;

	if (btn == MOUSE_LEFT || btn == MOUSE_SCROLL_UP || btn == MOUSE_SCROLL_DOWN)
	{
		c = pixel_to_complex(x, y, &(win->cmp));
		if (btn == MOUSE_SCROLL_UP)
			win->cmp.zoom *= 1.2;
		else if (btn == MOUSE_SCROLL_DOWN)
			win->cmp.zoom *= 0.8;
		else if (btn == MOUSE_LEFT)
		{
			win->cmp.c_x = c.re;
			win->cmp.c_y = c.im;
		}
		black_img(&(win->img));
		fractal(win, win->cmp.f);
		mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	}
	return (0);
}

int	mouse_move(int x, int y, t_win *win)
{
	t_coord	c;

	if (!(win->flag) && x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		c = pixel_to_complex(x, y, &(win->cmp));
		win->cmp.c_base.re = c.re;
		win->cmp.c_base.im = c.im;
		black_img(&(win->img));
		fractal(win, win->cmp.f);
		mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	}
	return (0);
}

int	change_phase(int btn, int x, int y, t_win *win)
{
	if (btn == MOUSE_LEFT)
	{
		(void)x;
		(void)y;
		win->flag = 1;
		phase2(*win);
	}
	return (0);
}
