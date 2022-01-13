/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:51:35 by incshin           #+#    #+#             */
/*   Updated: 2022/01/11 09:14:53 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	int	alphabet;

	alphabet = 'a';
	while (alphabet <= 'z')
	{
		write (1, &alphabet, 1);
		alphabet++;
	}
}
