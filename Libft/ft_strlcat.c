/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:28:36 by incshin           #+#    #+#             */
/*   Updated: 2022/03/11 18:37:24 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	dst_len;
// 	size_t	src_len;

// 	dst_len = ft_strlen(dst);
// 	src_len = ft_strlen(src);
// 	if (!dstsize)
// 		return (src_len);
// 	i = 0;
// 	while ((dst_len + i < dstsize - 1) && (src[i] != '\0'))
// 	{
// 		dst[dst_len + i] = src[i];
// 		i++;
// 	}
// 	dst[dst_len + i] = '\0';
// 	if (dst_len > dstsize)
// 		return (dstsize + src_len);
// 	return (dst_len + src_len);
// }
size_t ft_strlcat(dst, src, siz)
	char *dst;
	const char *src;
	size_t siz;
{
	register char *d = dst;
	register const char *s = src;
	register size_t n = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + ft_strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}