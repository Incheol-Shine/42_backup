/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:45:10 by incshin           #+#    #+#             */
/*   Updated: 2022/01/19 11:45:13 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int	plsmns;
	int	i;
	int	number;

	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	plsmns = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			plsmns *= -1;
		i++;
	}
	number = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (plsmns * number);
}
