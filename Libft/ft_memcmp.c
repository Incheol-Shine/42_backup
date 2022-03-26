/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:13:07 by incshin           #+#    #+#             */
/*   Updated: 2022/03/26 12:13:07 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*t1;
	const char	*t2;
	size_t		i;

	t1 = s1;
	t2 = s2;
	i = 0;
	while (t1[i] != '\0' && t2[i] != '\0' && i < n)
	{
		if (t1[i] - t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}
