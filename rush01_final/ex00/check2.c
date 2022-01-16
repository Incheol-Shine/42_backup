/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchae <suchae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:33:16 by suchae            #+#    #+#             */
/*   Updated: 2022/01/16 19:33:35 by suchae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_cnt = 0;
int		g_flag = 0;
int		g_edge[10][10];
int		g_ok[10];

int		check2(char **bord, int n, int r, int c);
void	init(int n, int ab[]);

int	check2_loop(char **bord, int n, int r, int c)
{
	int	j;

	j = 0;
	init(n, g_ok);
	while (j <= c)
	{
		g_ok[bord[r][j] - '0' - 1]++;
		if (g_ok[bord[r][j] - '0' - 1] >= 2)
		{
			return (0);
		}
		j++;
	}
	init(n, g_ok);
	j = 0;
	while (j <= r)
	{
		g_ok[bord[j][c] - '0' - 1]++;
		if (g_ok[bord[j][c] - '0' - 1] >= 2)
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	check2(char **bord, int n, int r, int c)
{
	return (check2_loop(bord, n, r, c));
}
