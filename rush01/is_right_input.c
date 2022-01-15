#include <stdio.h>

int	is_right_input(char *str);
int	ft_strlen(char *str);
int	g_edge[10][10];

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_right_input(char *str)
{
	int	str_len;
	int	n;
	int	i;
	int j;

	str_len = ft_strlen(str);
	if ((str_len + 1) % 8 != 0)
		return (0);
	n = (str_len + 1) / 8;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2 * n)
		{
			if (j % 2 == 0)
			{
				if (str[2 * n * i + j] < '1' || n + '0' < str[2 * n * i + j])
					return (1);
				else
					g_edge[i][j / 2] = str[(2 * n * i) + j] - '0';
			}
			else if (i < 3 && str[2 * n * i + j] != ' ')
				return (2);
			j++;
		}
		i++;
	}
	return (n);
}
