/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:11:39 by incshin           #+#    #+#             */
/*   Updated: 2022/01/26 20:03:39 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int			*ptr;
	long long	i;

	if (min >= max)
		return (NULL);
	ptr = (int *)malloc(sizeof(int) * ((long long)max - (long long)min));
	if (!ptr)
		return (0);
	i = 0;
	while (min < max)
		ptr[i++] = min++;
	return (ptr);
}
