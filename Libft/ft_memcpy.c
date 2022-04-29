/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:50:38 by incshin           #+#    #+#             */
/*   Updated: 2022/04/29 19:38:16 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;

	temp_dst = dst;
	temp_src = src;
	if ((!temp_dst) && (!temp_src))
		return (0);
	while (n--)
		temp_dst[n] = temp_src[n];
	return (dst);
}

int	main(void)
{
	char *dst = "     ";
	const char *src = NULL;

	printf("%s", (char *)ft_memcpy(dst, src, 3));
}