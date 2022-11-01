#include <mlx.h>
#include <stdio.h>
 


void	mouse_move(int x, int y, int *p_cnt)
{
	if (x >= 0 && x < 640 && y >=0 && y < 480)
		printf("%d, %d\n", x, y);
}

void	mouse_down(int btn, int x, int y, int *p_cnt)
{
	printf("btn down: %d\ncoord : %d, %d\n", btn, x, y);
}

void	mouse_up(int btn, int x, int y, int *p_cnt)
{
	printf("btn up: %d\ncoord : %d, %d\n", btn, x, y);
}

typedef	struct s_coord
{
	double	re;
	double	im;
}				t_coord;

t_coord	pixel_to_complex(int x, int y)
{
	t_coord c;
	double	zoom;
	double	c_x = 1;
	double	c_y = 1;

	printf("x: %d, y: %d\n",x,y);
	zoom = 640 / 4;
	c.re = x / zoom - 640 / (2 * zoom) + c_x;
	c.im = -y / zoom + 480 / (2 * zoom) + c_y;
	printf("%lf, %lf\n", c.re, c.im);
	return (c);
}

typedef struct	s_img
{
	void	*img;
	void	*black_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void    key_hook(int keycode, t_img *img)
{
    printf("key_hook...%d\n", keycode);
    *p_cnt += 1;
}

int        main(void)
{
	t_img	img;
    int        cnt;
    void    *mlx;
    void    *win;
 
    cnt = 0;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "title");
	img.img = mlx_new_image(mlx, 640, 480);
    mlx_key_hook(win, &key_hook, &img);





	// mlx_mouse_hook(win, &mouse_move, &cnt);
	// mlx_mouse_hook(win, &mouse_down, &cnt);
	// mlx_mouse_hook(win, &mouse_up, &cnt);
	// pixel_to_complex(0, 0);
	// pixel_to_complex(320, 240);
	// pixel_to_complex(640, 480);
	// mlx_hook(win, 6, 0, &mouse_move, &cnt);
	// mlx_hook(win, 4, 0, &mouse_down, &cnt);
	// mlx_hook(win, 5, 0, &mouse_up, &cnt);

    mlx_loop(mlx);
    return (0);    
}