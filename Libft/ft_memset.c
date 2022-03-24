/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:00:36 by incshin           #+#    #+#             */
/*   Updated: 2022/03/24 16:35:01 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = b;
	if (!temp)
		return (0);
	while (len--)
		*(temp + len) = (unsigned char)c;
	return (b);
}
