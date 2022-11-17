/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:43 by incshin           #+#    #+#             */
/*   Updated: 2022/11/17 20:30:16 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_atoi(const char *str)
{
	long	i;
	long	sign;
	long	answer;

	i = 0;
	sign = (str[i] != '-') * 2 - 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	answer = 0;
	while (ft_isdigit(str[i]))
	{
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] && (!ft_isdigit(str[i])))
		print_error_exit(ATOI_ERR);
	answer *= sign;
	if (answer > 2147483647 || answer < -2147483648)
		print_error_exit(ATOI_ERR);
	return ((int)answer);
}

int	*str_to_int_arr(int size, char *argv[])
{
	int	*numbers;
	int	i;

	numbers = (int *)malloc(sizeof(int) * (size));
	if (!numbers)
		print_error_exit(MALLOC_ERR);
	i = 0;
	while (i < size)
	{
		numbers[i] = push_swap_atoi(argv[i + 1]);
		i++;
	}
	return (numbers);
}

void	check_already_sort(int size, int *numbers)
{
	int	i;
	int	already_sorted;

	i = 0;
	already_sorted = 1;
	while (i < size - 1)
	{
		if (numbers[i] > numbers[i + 1])
		{
			already_sorted = 0;
			return ;
		}
		i++;
	}
	if (already_sorted)
		exit(0);
}

int	*bubble_sort(int size, int *numbers)
{
	int	*sorted_nbr;
	int	i;

	sorted_nbr = (int *)malloc(sizeof(int) * (size));
	if (!sorted_nbr)
		print_error_exit(MALLOC_ERR);
	ft_memcpy(sorted_nbr, numbers, sizeof(int) * size);
	while (size > 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (sorted_nbr[i] == sorted_nbr[i + 1])
				print_error_exit(ARG_ERR);
			else if (sorted_nbr[i] > sorted_nbr[i + 1])
				ft_swap(sorted_nbr + i, sorted_nbr + i + 1);
			i++;
		}
		size--;
	}
	return (sorted_nbr);
}

void	check_overlap_pivot(int size, int *numbers, t_pivot *pivot)
{
	int	*sorted_nbr;
	int	i;

	sorted_nbr = bubble_sort(size, numbers);
	i = 0;
	while (i < size - 1)
	{
		if (sorted_nbr[i] == sorted_nbr[i + 1])
			print_error_exit(ARG_ERR);
		i++;
	}
	pivot->one_third = sorted_nbr[size / 3];
	pivot->two_third = sorted_nbr[2 * size / 3];
	free(sorted_nbr);
}

/*
	for (int j=0; j<size; j++)
		ft_printf("%d ", sorted_nbr[j]);
	ft_printf("\n");
*/
