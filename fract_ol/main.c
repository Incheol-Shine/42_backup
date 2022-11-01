#include "fractol.h"

#define	WIN_WIDTH			960
#define	WIN_HEIGHT			540
#define	MAX_ITER			100
#define KEY_ESC				65307 // mac : 53, linux : 65307

#define MOUSE_LEFT			1
#define MOUSE_SCROLL_UP		4
#define MOUSE_SCROLL_DOWN	5


int	key_hook(int keycode, t_win *win)
{
    printf("key_hook...%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(win->mlx, win->win);
		mlx_destroy_image(win->mlx, win->img.img);
		exit(0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

int	mouse_zoom(int btn, int x, int y, t_win *win)
{
	t_coord c;

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
	mlx_destroy_image(win->mlx, win->img.img);
	win->img.img = mlx_new_image(win->mlx, WIN_WIDTH, WIN_HEIGHT);
	fractal(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	c = pixel_to_complex(x, y, &(win->cmp));
	return (0);
}

t_coord	pixel_to_complex(int x, int y, t_complex *cmp)
{
	t_coord c;

	c.re = x / cmp->zoom - WIN_WIDTH / (2 * cmp->zoom) + (cmp->c_x);
	c.im = -y / cmp->zoom + WIN_HEIGHT / (2 * cmp->zoom) + (cmp->c_y);
	// printf("%lf, %lf\n", c.re, c.im);
	return (c);
}

void	make_circle(t_win *win, double d)
{
	t_coord c;
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c = pixel_to_complex(x, y, &(win->cmp));
			if (c.re*c.re + c.im*c.im <= (d*d))
			{
				my_mlx_pixel_put(&(win->img), x, y, 0x00FFFFFF);
			}
			x++;
		}
		y++;
	}
}

unsigned int	mandelbrot(t_coord c)
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

unsigned int	mandelbrot(t_coord c)
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
	float			release_rate;
	int 			r;
	int 			g;
	int 			b;
	unsigned int	color;

	release_rate = (float)iter / (float)(MAX_ITER);
	r = 255 * (1 - release_rate);
	g = 255 * (1 - release_rate);
	b = 255 * (1 - release_rate);
	color = r << 16 | g << 8 | b;
	return ((1 << 24) * (1-release_rate));
	// return (color);
}

void	fractal(t_win *win, int	fractal_set)
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
			if ((iteration = mandelbrot(pixel_to_complex(x, y, &(win->cmp)))))
			{
				my_mlx_pixel_put(&(win->img), x, y, set_color(iteration));
			}
			x++;
		}
		y++;
	}
}

void	init(t_win *win)
{
	win->mlx = mlx_init();
    win->win = mlx_new_window(win->mlx, WIN_WIDTH, WIN_HEIGHT, "title");
	win->img.img = mlx_new_image(win->mlx, WIN_WIDTH, WIN_HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel, &win->img.line_length, &win->img.endian);
    win->cmp.c_x = 0;
	win->cmp.c_y = 0;
	win->cmp.zoom = WIN_WIDTH / 4;
}

void	error_msg(void)
{
	printf("usage : fractol [mandelbrot julia]");
	exit(0);
}

int	choice(char *set, unsigned int (*f)(t_coord a, t_win *b))
{
	char *mandel;
	char *julia;

	mandel = "mandelbrot";
	julia = "julia";
	if (ft_strncmp(set, "mandelbrot", 10))
		f = &mandelbrot;
	else if (ft_strncmp(set, "julia", 5))
		f = &julia;
	else if (ft_strncmp(set, "ship", 4))
		f = &ship;
	else
		error_msg();
	return (0);
}

int	main(int argc, char *argv[])
{
    t_win	win;
	int		fractal_set;
	
	if (argc != 2)
		error_msg();
	choice(argv[1], win.cmp.f);
	init(&win);
	
	fractal(&win, fractal_set);
	
	mlx_put_image_to_window(win.mlx, win.win, win.img.img, 0, 0);
	mlx_mouse_hook(win.win, &mouse_zoom, &win);
	mlx_key_hook(win.win, &key_hook, &win);
    mlx_loop(win.mlx);
    return (0);
}