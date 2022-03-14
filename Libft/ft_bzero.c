/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:11:57 by incshin           #+#    #+#             */
/*   Updated: 2022/03/14 16:47:50 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = s;
	if (!temp)
		return (0);
	while (n)
		temp[--n] = 0;
	return (s);
}