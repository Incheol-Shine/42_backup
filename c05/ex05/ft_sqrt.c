/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:03 by incshin           #+#    #+#             */
/*   Updated: 2022/01/22 19:19:05 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);
int	recursive(int nb, int x);

int	recursive(int nb, int x)
{
	if ((x == nb / x) && (nb % x) == 0)
		return (x);
	if (x > nb / x)
		return (0);
	return (recursive(nb, x + 1));
}

int	ft_sqrt(int nb)
{
	return (recursive(nb, 1));
}
