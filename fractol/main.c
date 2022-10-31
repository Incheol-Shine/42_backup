#include "fractol.h"

#define		WIN_WIDTH				960
#define		WIN_HEIGHT				540
#define		MAX_ITER				20

#define		EVENT_MOUSE_MOVE		6
#define		EVENT_MOUSE_DOWN		4
#define		EVENT_MOUSE_up			5




void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	make_circle(t_img *img, float d, int scale)
// {
// 	d *= scale;
// 	for (float y = -WIN_HEIGHT / 2; y <= WIN_HEIGHT / 2; y++)
// 		for (int x = -WIN_WIDTH / 2; x <= WIN_WIDTH / 2; x++)
// 			if (x*x + y*y <= (int)(d*d))
// 				complex_pixel_put(img, x, y, 0x00FFFFFF);
// }

void	black_img(t_img *img)
{
	int x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

t_coord	pixel_to_complex(t_win *win, int x, int y)
{
	t_coord c;

	c.re = x / *(win->complex.zoom) - WIN_WIDTH / 2 * *(win->complex.zoom) + *(win->complex.c_x);
	c.im = -y / *(win->complex.zoom) - WIN_HEIGHT / 2 * *(win->complex.zoom) + *(win->complex.c_y);
	return (c);
}

unsigned int	is_release(t_coord c)
{
	t_coord	z;
	double	temp;
	int		num_iter;

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

unsigned int	set_color(int iter)
{
	float	release_rate;
	int 	r;
	int 	g;
	int 	b;
	unsigned int	color;

	release_rate = (float)iter / (float)(MAX_ITER);
	r = 255 * (1 - release_rate);
	g = 255 * (1 - release_rate);
	b = 255 * (1 - release_rate);
	color = r << 16 | g << 8 | b;
	return ((1 << 24) * (1-release_rate));
	// return (color);
}



void	mandelbrot(t_win *win)
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
			if ((iteration = is_release(pixel_to_complex(win, x, y))))
			{
				my_mlx_pixel_put(win->img.img, x, y, set_color(iteration));
			}
			x++;
		}
		y++;
	}
}


void	init(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	win->img.img = mlx_new_image(win->mlx, WIN_WIDTH, WIN_HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel, \
										&win->img.line_length, &win->img.endian);
	*(win->complex.c_x) = WIN_WIDTH / 2;
	*(win->complex.c_y) = WIN_WIDTH / 2;
	*(win->complex.zoom) = WIN_WIDTH / 4;
	win->img.black_img = mlx_new_image(win->mlx, WIN_WIDTH, WIN_HEIGHT);
	black_img(win->img.black_img);
}

int		main(void)
{
	t_win	win;
	
	init(&win);
	mandelbrot(&win);
	mlx_put_image_to_window(win.mlx, win.win, win.img.img, 0, 0);
	mlx_key_hook(win.win, &press_key, &win);
	mlx_mouse_hook(win.win, &zoom_in_out, &win);
	// mlx_hook(win.win, EVENT_MOUSE_DOWN, 0, &zoom_in_out, &win);
	mlx_loop(win.mlx);
}

