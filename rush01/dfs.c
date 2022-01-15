void DFS_bord(char **bord, int n, int r, int c, char *arr);
void print_bord(char **bord);
int g_edge[10][10];

void print_bord(char **bord)
{	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%c", bord[i][j]);
		}
		printf("\n");
	}
}

void DFS_bord(char **bord, int n, int r, int c, char *arr)
{
	int	i;
	int	j;
	int k;
	if (r == n && c == n)
	{
		print_bord(bord);
		return;
	}
	else
	{
		i = 1
		while (i <= n)
		{
			bord[r][c] = i;
			if (check(bord, r, c))
			{
				j = r;
				while (j <= n)
				{
					k = c;
					while (k <= n)
					{
						//b[r][c] arr보고 결정
						DFS_bord(bord, n, r, c+1, arr);
						k++;
					}
					j++;
				}
			}
			i++;
		}
}
