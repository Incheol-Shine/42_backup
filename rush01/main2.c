#include <stdio.h>
int	is_right_input(char *str);
int g_edge[10][10];

int main()
{
	char	str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
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
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d ", g_edge[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
