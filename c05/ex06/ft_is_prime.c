/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:43 by incshin           #+#    #+#             */
/*   Updated: 2022/01/22 19:20:16 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);
int	ft_sqrt(int nb, int x);
int	ft_prime_sub(int nb, int sqrt);

int	ft_sqrt(int nb, int x)
{
	if ((x >= nb / x))
		return (x);
	else
		return (ft_sqrt(nb, x + 1));
}

int	ft_prime_sub(int nb, int sqrt)
{
	if (sqrt <= 1)
		return (1);
	if (nb == 2)
		return (1);
	if (nb % sqrt == 0)
		return (0);
	return (ft_prime_sub(nb, sqrt - 1));
}

int	ft_is_prime(int nb)
{
	int	sqrt;

	if (nb <= 1)
		return (0);
	sqrt = ft_sqrt(nb, 1);
	return (ft_prime_sub(nb, sqrt));
}
