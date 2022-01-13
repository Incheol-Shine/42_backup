/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:53:05 by incshin           #+#    #+#             */
/*   Updated: 2022/01/11 17:55:51 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_comb2(void);
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

void	ft_print_comb2(void)
{
	char	arr[4];

	arr[0] = '0';
	arr[1] = '0';
	arr[2] = '0';
	arr[3] = '1';
	write(1, arr, 2);
	write(1, " ", 1);
	write(1, arr + 2, 2);
	arr[3]++;
	while (arr[0] <= '9' && arr[1] <= '9')
	{
		if (((arr[0] == arr[2]) && (arr[1] < arr[3])) || (arr[0] < arr[2]))
		{
			write(1, ", ", 2);
			write(1, arr, 2);
			write(1, " ", 1);
			write(1, arr + 2, 2);
		}
		arr[3]++;
		carry_number(arr, 4);
	}
}
