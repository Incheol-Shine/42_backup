/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:06:10 by incshin           #+#    #+#             */
/*   Updated: 2022/11/02 04:26:33 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct s_coord
{
	double	re;
	double	im;
}				t_coord;

typedef struct	s_img
{
	void	*img;
	void	*black_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_complex
{
	double			c_x;
	double			c_y;
	double			zoom;
	t_coord			c_base;
	unsigned int	(*f)(t_coord a, t_coord b);
}				t_complex;

typedef struct	s_win
{
	t_img		img;
	t_complex	cmp;
	void		*mlx;
	void		*win;
}				t_win;

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				mouse_zoom(int btn, int x, int y, t_win *win);
int				mouse_move(int x, int y, t_win *win);
t_coord			pixel_to_complex(int x, int y, t_complex *cmp);
unsigned int	mandelbrot(t_coord c, t_coord a);
unsigned int	julia(t_coord c, t_coord a);
unsigned int	ship(t_coord c, t_coord a);
unsigned int	set_color(int iter);
void			fractal(t_win *win, unsigned int (*set)(t_coord a, t_coord b));
int				change_phase(int btn, int x, int y, t_win *win);
int				phase0(t_win win);
int				phase1(t_win win);
int				phase2(t_win win);
int				choice(char *set, t_win *win);
void			error_msg(void);
#endif