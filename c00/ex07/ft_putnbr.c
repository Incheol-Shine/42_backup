/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:53:20 by incshin           #+#    #+#             */
/*   Updated: 2022/01/11 09:49:41 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putnbr(int nb);
void	recursive(int nb, int plsMns);

void	recursive(int nb, int plsMns)
{
	int	num;

	if ((nb / 10) == 0)
	{
		num = (nb * plsMns) + '0';
		write(1, &num, 1);
	}
	else
	{
		recursive(nb / 10, plsMns);
		num = ((nb % 10) * plsMns) + '0';
		write(1, &num, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
	{
		recursive(nb, 1);
	}
	else
	{
		write(1, "-", 1);
		recursive(nb, -1);
	}
}
