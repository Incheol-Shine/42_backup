/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:43:23 by incshin           #+#    #+#             */
/*   Updated: 2022/03/28 11:03:23 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;

	temp = s;
	while (n)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		temp++;
		n--;
	}
	return (0);
}
