/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:57:45 by incshin           #+#    #+#             */
/*   Updated: 2022/01/22 10:45:06 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	answer;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	answer = 1;
	while (power > 0)
	{
		answer *= nb;
		power--;
	}
	return (answer);
}
