/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:45:34 by incshin           #+#    #+#             */
/*   Updated: 2022/01/19 11:45:38 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putnbr(int nb);
void	recursive(int nb, int plsmns);

void	recursive(int nb, int plsmns)
{
	char	c;

	if (nb / 10 == 0)
	{
		c = (nb * plsmns) + '0';
		write(1, &c, 1);
	}
	else
	{
		recursive(nb / 10, plsmns);
		c = ((nb % 10) * plsmns) + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
		recursive(nb, 1);
	else
	{
		write(1, "-", 1);
		recursive(nb, -1);
	}
}
