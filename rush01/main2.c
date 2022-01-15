#include <stdio.h>
#include <stdlib.h>
int	is_right_input(char *str);
int g_edge[10][10];
void DFS_bord(int **bord, int n, int r, int c);
int g_flg;
int main()
{
	// char	str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	char	str[] = "1 2 2 1 1 2 2 1";
	int		n;
	int		i;
	int 	j;

	n = is_right_input(str);
	if (n == 0)
	{
		printf("error - wrong input\n");
		return (0);
	}	
	printf("n : %d\n", n);

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			printf("%d ", g_edge[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	int **bord = NULL;
	bord = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		bord[i] = (int*)malloc(sizeof(int)*n);
	g_flg = 0;
	DFS_bord(bord, n, 0, 0);
	if (g_flg == 0)
		printf("error");
	else
		printf("good");
}
