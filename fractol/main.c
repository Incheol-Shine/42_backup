/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:19:28 by incshin           #+#    #+#             */
/*   Updated: 2022/11/02 13:58:50 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	choice(char *set, t_win *win)
{
	if (!(ft_strncmp(set, "mandelbrot", 11)))
		win->cmp.f = &mandelbrot;
	else if (!(ft_strncmp(set, "ship", 11)))
		win->cmp.f = &ship;
	else if (!(ft_strncmp(set, "julia", 11)))
	{
		win->cmp.f = &julia;
		return (1);
	}
	else
		error_msg();
	return (0);
}

int	main(int argc, char *argv[])
{
	t_win	win;
	int		is_julia;

	if (argc != 2)
		error_msg();
	is_julia = choice(argv[1], &win);
	init(&win);
	fractal(&win, win.cmp.f);
	mlx_put_image_to_window(win.mlx, win.win, win.img.img, 0, 0);
	if (is_julia)
		phase1(win);
	else
		phase0(win);
	return (0);
}

void	phase0(t_win win)
{
	mlx_hook(win.win, 4, 0, &mouse_zoom, &win);
	mlx_key_hook(win.win, &key_hook, &win);
	mlx_loop(win.mlx);
}

void	phase1(t_win win)
{
	mlx_hook(win.win, 6, 0, &mouse_move, &win);
	mlx_hook(win.win, 4, 0, &change_phase, &win);
	mlx_key_hook(win.win, &key_hook, &win);
	mlx_loop(win.mlx);
}

void	phase2(t_win win)
{
	mlx_mouse_hook(win.win, &mouse_zoom, &win);
	mlx_key_hook(win.win, &key_hook, &win);
	mlx_loop(win.mlx);
}
