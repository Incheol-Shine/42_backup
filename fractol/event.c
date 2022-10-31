/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:06:29 by incshin           #+#    #+#             */
/*   Updated: 2022/10/31 14:45:40 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define KEY_ESC			53
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
		win->scale *= 1.1;
	else if (btn == MOUSE_SCROLL_DOWN)
		win->scale *= 0.9;
	black_img(&win->img);
	mandelbrot(&win->img, win->scale);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	return (0);
}
