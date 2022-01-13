/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:53:40 by incshin           #+#    #+#             */
/*   Updated: 2022/01/11 09:59:28 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	dfs(char arr[], int cand, int depth, int n);
const int	g_n = 10;

void	dfs(char arr[], int cand, int depth, int n)
{
	int	i;

	if (depth == n)
	{
		write(1, arr, n);
		if (arr[0] != g_n - n + '0')
			write(1, ", ", 2);
	}
	else
	{
		i = cand;
		while (i < g_n)
		{
			arr[depth] = i + '0';
			dfs(arr, i + 1, depth + 1, n);
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	dfs(arr, 0, 0, n);
}
