/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:16:29 by incshin           #+#    #+#             */
/*   Updated: 2022/01/22 19:25:20 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int		ft_ten_queen_puzzle(void);
int		recursive(int *arr, int r, int c, int cnt);
void	print_board(int *arr);
int		is_right_place(int *arr, int r, int c);
int		ft_abs(int nb);

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

void	print_board(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_right_place(int *arr, int r, int c)
{
	int	i;

	if (arr[c] != -1)
		return (0);
	if (r == 0)
		return (1);
	i = 0;
	while (i < 10)
	{
		if (arr[i] != -1 && ft_abs(r - arr[i]) == ft_abs(c - i))
			return (0);
		i++;
	}
	return (1);
}

int	recursive(int *arr, int r, int c, int cnt)
{
	if (r == 10)
	{
		print_board(arr);
		cnt++;
		return (cnt);
	}
	else
	{
		while (c < 10)
		{
			if (is_right_place(arr, r, c))
			{
				arr[c] = r;
				cnt = recursive(arr, r + 1, 0, cnt);
				arr[c] = -1;
			}
			c++;
		}
	}
	return (cnt);
}

int	ft_ten_queen_puzzle(void)
{
	int	arr[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		arr[i] = -1;
		i++;
	}
	return (recursive(arr, 0, 0, 0));
}
