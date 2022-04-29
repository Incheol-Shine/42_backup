/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:49:09 by incshin           #+#    #+#             */
/*   Updated: 2022/04/29 19:54:09 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	answer;

	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	sign = (str[i] != '-') * 2 - 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	answer = 0;
	while (ft_isdigit(str[i]))
	{
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	return (sign * answer);
}
int main(void)
{
	printf("%d\n", atoi("9223372036854775807"));
	printf("%d", ft_atoi("9223372036854775807"));
		
}