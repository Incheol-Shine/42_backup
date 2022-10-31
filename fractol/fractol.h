/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:06:10 by incshin           #+#    #+#             */
/*   Updated: 2022/10/30 18:24:42 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;
typedef struct	s_win
{
	void	*mlx;
	void	*win;
}				t_win;
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			complex_pixel_put(t_img *img, int x, int y, int color);
void			make_circle(t_img *img, float d, int scale);
unsigned int	is_release(double c_re, double c_im);
unsigned int	set_color(int iter);
void			mandelbrot(t_img *img, int scale);
int				close(int keycode, t_win *vars);

#endif