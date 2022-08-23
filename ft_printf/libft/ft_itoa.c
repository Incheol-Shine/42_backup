/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:12:46 by incshin           #+#    #+#             */
/*   Updated: 2022/03/31 11:16:12 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	arrsize(int n);

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	char	*temp;

	sign = 1;
	if (n < 0)
		sign = -1;
	size = arrsize(n) + (-1 * (sign - 1) / 2);
	temp = (char *)malloc(size + 1);
	if (!temp)
		return (0);
	temp[size] = '\0';
	while (size)
	{
		temp[size - 1] = (n % 10) * sign + '0';
		n /= 10;
		size--;
	}
	if (sign < 0)
		temp[0] = '-';
	return (temp);
}

static int	arrsize(int n)
{
	int	i;

	if (-10 < n && n < 10)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
