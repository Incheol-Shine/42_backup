/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchae <suchae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:33:23 by suchae            #+#    #+#             */
/*   Updated: 2022/01/16 19:33:30 by suchae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_edge[10][10];
int		g_sum[4];

int		check(char **bord, int n, int r, int c);
void	init(int n, int ab[]);

void	init(int n, int ab[])
{
	int	i;

	i = 0;
	while (i < n)
	{
		ab[i] = 0;
		i++;
	}
}

void	check_sub_loop(char **bord, int n, int r, int c)
{
	int	j;
	int	max[2];

	init(2, max);
	j = 0;
	while (j <= c)
	{
		if (max[0] < bord[r][j] - '0')
		{
			max[0] = bord[r][j] - '0';
			g_sum[2]++;
		}
		if (max[1] < bord[r][n - j - 1] - '0' && n - 1 == c)
		{
			max[1] = bord[r][n - j - 1] - '0';
			g_sum[3]++;
		}
		j++;
	}
}

void	check_sub_loop2(char **bord, int n, int r, int c)
{
	int	i;
	int	max[2];

	init(2, max);
	i = 0;
	while (i <= r)
	{
		if (max[0] < bord[i][c] - '0')
		{
			max[0] = bord[i][c] - '0';
			g_sum[0]++;
		}
		if (max[1] < bord[n - 1 - i][c] - '0' && n - 1 == r)
		{
			max[1] = bord[n - 1 - i][c] - '0';
			g_sum[1]++;
		}
		i++;
	}
}

int	check(char **bord, int n, int r, int c)
{
	int	flag[6];

	init(6, flag);
	init(4, g_sum);
	check_sub_loop(bord, n, r, c);
	check_sub_loop2(bord, n, r, c);
	flag[3] = (g_sum[3] == g_edge[3][r]);
	flag[1] = (g_sum[1] == g_edge[1][c]);
	flag[5] = (g_sum[2] <= g_edge[2][r]);
	flag[4] = (g_sum[0] <= g_edge[0][c]);
	flag[2] = (g_sum[2] == g_edge[2][r]);
	flag[0] = (g_sum[0] == g_edge[0][c]);
	if (r == n - 1 && c == n - 1)
		return (flag[3] && flag[1] && flag[2] && flag[0]);
	else if (r == n - 1)
		return (flag[1] && flag[5] && flag[0]);
	else if (c == n - 1)
		return (flag[3] && flag[2] && flag[4]);
	else
		return (flag[5] && flag[4]);
}
