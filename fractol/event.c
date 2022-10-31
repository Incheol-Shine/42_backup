/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:06:29 by incshin           #+#    #+#             */
/*   Updated: 2022/11/01 08:20:55 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define KEY_ESC			65307 // mac : 53, linux : 65307
# define MOUSE_LEFT			1
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

int	press_key(int keycode, t_win *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	zoom_in_out(int btn, int x, int y, t_win *win)
{	
	if (btn == MOUSE_SCROLL_UP)
		*(win->complex.zoom) *= 1.1;
	else if (btn == MOUSE_SCROLL_DOWN)
		*(win->complex.zoom) *= 0.9;
	mlx_put_image_to_window(win->mlx, win->win, win->img.black_img, 0, 0);
	mandelbrot(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	return (0);
}
