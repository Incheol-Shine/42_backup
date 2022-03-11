/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:52:54 by incshin           #+#    #+#             */
/*   Updated: 2022/03/11 17:09:58 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;

	temp_dst = dst;
	temp_src = src;
	while (n--)
		temp_dst[n] = temp_src[n];
	return (dst);
}