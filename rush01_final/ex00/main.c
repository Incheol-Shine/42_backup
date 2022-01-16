/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemilee <jaemilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:29:07 by jaemilee          #+#    #+#             */
/*   Updated: 2022/01/16 19:10:55 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
int		is_right_input(char *str);
int		g_edge[10][10];
void	DFS_bord(char **bord, int n, int r, int c);
int		g_flg;
int		g_ok[10][10];

void	init_bord(char **bord2, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			bord2[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	set_bord(char ***bord, int n)
{
	int		i;
	char	**bord2;

	bord2 = (char **)malloc(sizeof(char *) * n);
	if (bord2 == NULL)
		return ;
	i = 0;
	while (i < n)
	{
		bord2[i] = (char *)malloc(sizeof(char) * n);
		if (bord2[i] == NULL)
			return ;
		i++;
	}
	init_bord(bord2, n);
	*bord = bord2;
}

void	free_bord(char **bord, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(bord[i]);
		i++;
	}
	free(bord);
}

int	main(int argc, char *argv[])
{
	int		n;
	char	**bord;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	n = is_right_input(argv[1]);
	if (n == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	bord = NULL;
	set_bord(&bord, n);
	g_flg = 0;
	DFS_bord(bord, n, 0, 0);
	if (g_flg == 0)
		write(1, "Error\n", 6);
	free_bord(bord, n);
}
