#include <stdio.h>
void DFS_bord(int **bord, int n, int r, int c);
void print_bord(int **bord, int n);
int check(int **bord,int n,int r,int c);
int g_edge[10][10];
int g_flg;

void print_bord(int **bord, int n)
{	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d", bord[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void DFS_bord(int **bord, int n, int r, int c)
{
	int	i;
	int	j;
	int k;

	if (r == n && c == 0)
	{
		print_bord(bord, n);
		g_flg = 1;
		printf("flag : %d\n",g_flg);
	}
	else
	{
		i = 1;
		while (i <= n)
		{
			bord[r][c] = i;
			if (check(bord, n, r, c))
			{
				if (c < n-1)
					DFS_bord(bord, n, r, c+1); 
				else if (c = n-1 && r < n)
					DFS_bord(bord, n, r+1, 0);
			}
			i++;
		}
	}
}
