#include <mlx.h>
#include <stdio.h>
 
void    key_hook(int keycode, int *p_cnt)
{
    printf("key_hook...%d\n", keycode);
    *p_cnt += 1;
}

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
 
int        main(void)
{
    int        cnt;
    void    *mlx;
    void    *win;
 
    cnt = 0;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "title");
    mlx_key_hook(win, &key_hook, &cnt);
	mlx_hook(win, 6, 0, &mouse_move, &cnt);
	mlx_hook(win, 4, 0, &mouse_down, &cnt);
	mlx_hook(win, 5, 0, &mouse_up, &cnt);
    mlx_loop(mlx);
    return (0);    
}