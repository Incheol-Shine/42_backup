#include "fractol.h"

#define		WIN_WIDTH				1920
#define		WIN_HEIGHT				1080
#define		MAX_ITER				50

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	complex_pixel_put(t_img *img, int x, int y, int color)
{
	x = (x + WIN_WIDTH / 2);
	y = (-y + WIN_HEIGHT / 2);
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	my_mlx_pixel_put(img, x, y, color);
}

void	make_circle(t_img *img, float d, int scale)
{
	d *= scale;
	for (float y = -WIN_HEIGHT / 2; y <= WIN_HEIGHT / 2; y++)
		for (int x = -WIN_WIDTH / 2; x <= WIN_WIDTH / 2; x++)
			if (x*x + y*y <= (int)(d*d))
				complex_pixel_put(img, x, y, 0x00FFFFFF);
}

unsigned int	is_release(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		num_iter;

	z_re = 0;
	z_im = 0;
	num_iter = 0;
	while (num_iter < MAX_ITER)
	{
		if (z_re * z_re + z_im * z_im > 4)
			return (num_iter);
		temp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = temp;
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

	release_rate = (float)iter / (float)MAX_ITER;
	r = 255 * (1 - release_rate);
	g = 255 * (1 - release_rate);
	b = 255 * (1 - release_rate);
	color = r << 16 | g << 8 | b;
	return ((1 << 24) * (1-release_rate));
	// return (color);
}

void	mandelbrot(t_img *img, int scale)
{
	int				c_re;
	int 			c_im;
	int				iteration;

	c_im = -(WIN_HEIGHT / 2);
	while (c_im < WIN_HEIGHT / 2)
	{
		c_re = -(WIN_WIDTH / 2);
		while (c_re < WIN_WIDTH / 2)
		{
			if (iteration = is_release(c_re / (double)scale, c_im / (double)scale))
			{
				complex_pixel_put(img, c_re, c_im, set_color(iteration));
			}
			c_re++;
		}
		c_im++;
	}
}

int		main(void)
{
	t_img	img;
	t_win	win;
	int		scale;

	scale = WIN_WIDTH / 4;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	img.img = mlx_new_image(win.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("%d, %d, %d\n", img.bits_per_pixel, img.line_length, img.endian);
	mandelbrot(&img, scale);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_hook(win.win, 2, 1L<<0, close, &win);
	// esc_quit();
	mlx_loop(win.mlx);
}

