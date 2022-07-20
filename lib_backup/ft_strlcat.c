/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:28:36 by incshin           #+#    #+#             */
/*   Updated: 2022/04/22 13:30:49 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	i = 0;
	while ((dst_len + i < size - 1) && (src[i] != '\0'))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len > size)
		return (size + src_len);
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
