/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:30:18 by incshin           #+#    #+#             */
/*   Updated: 2022/01/16 18:38:48 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	DFS_bord(char **bord, int n, int r, int c);
void	print_bord(char **bord, int n);
int		check(char **bord, int n, int r, int c);
int		check2(char **bord, int n, int r, int c);
int		g_edge[10][10];
int		g_flg;

void	print_bord(char **bord, int n)
{	
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			write(1, *(bord + i) + j, 1);
			j++;
			if (j != n)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	DFS_bord(char **bord, int n, int r, int c)
{
	int	i;

	if (g_flg)
		return ;
	if (r == n && c == 0)
	{
		print_bord(bord, n);
		g_flg = 1;
	}
	else
	{
		i = 1;
		while (i <= n)
		{
			bord[r][c] = i + '0';
			if (check(bord, n, r, c) && check2(bord, n, r, c))
			{
				if (c < n - 1)
					DFS_bord(bord, n, r, c + 1);
				else if (c == n - 1 && r < n)
					DFS_bord(bord, n, r + 1, 0);
			}
			i++;
		}
	}
}
