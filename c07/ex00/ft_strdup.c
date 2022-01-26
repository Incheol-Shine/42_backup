/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:56:59 by incshin           #+#    #+#             */
/*   Updated: 2022/01/26 09:11:32 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	ptr = (char *)malloc(sizeof(int) * (len + 1));
	if (!ptr)
		return (0);
	while (len >= 0)
	{
		ptr[len] = src[len];
		len--;
	}
	return (ptr);
}
