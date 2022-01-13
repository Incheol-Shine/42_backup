/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:52:49 by incshin           #+#    #+#             */
/*   Updated: 2022/01/11 09:34:29 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	carry_number(char arr[], int size);

void	carry_number(char arr[], int size)
{
	while (size - 1 > 0)
	{
		if (arr[size - 1] > '9')
		{
			arr[size - 1] = '0';
			arr[size - 2]++;
		}
		else
		{
			break ;
		}
		size--;
	}
}

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = '0';
	arr[1] = '1';
	arr[2] = '2';
	write (1, arr, 3);
	arr[2]++;
	while (arr[0] <= '7')
	{
		if (arr[0] < arr[1] && arr[1] < arr[2])
		{
			write (1, ", ", 2);
			write (1, arr, 3);
		}
		arr[2]++;
		carry_number(arr, 3);
	}
}
