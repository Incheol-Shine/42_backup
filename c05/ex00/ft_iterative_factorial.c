/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:37:10 by incshin           #+#    #+#             */
/*   Updated: 2022/01/20 14:59:07 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	answer;

	if (nb < 0)
		return (0);
	answer = 1;
	while (nb > 0)
	{
		answer *= nb;
		nb -= 1;
	}
	return (answer);
}
