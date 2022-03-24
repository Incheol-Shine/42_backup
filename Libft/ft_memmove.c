/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:52:54 by incshin           #+#    #+#             */
/*   Updated: 2022/03/24 16:36:43 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;
	size_t		i;

	temp_dst = dst;
	temp_src = src;
	if (dst > src)
	{
		while (n--)
			temp_dst[n] = temp_src[n];
	}
	else if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
