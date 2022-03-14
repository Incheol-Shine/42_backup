/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:43:23 by incshin           #+#    #+#             */
/*   Updated: 2022/03/14 17:45:40 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;

	temp = s;
	while (n)
	{
		if (*temp == c)
			return ((void*)temp);
		temp++;
		n--;
	}
	return (0);
}