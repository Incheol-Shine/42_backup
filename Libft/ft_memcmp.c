/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:22:23 by incshin           #+#    #+#             */
/*   Updated: 2022/03/28 11:03:28 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;
	size_t		i;

	t1 = s1;
	t2 = s2;
	i = 0;
	while (t1[i] == t2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (t1[i] - t2[i]);
}
