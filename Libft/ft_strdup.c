/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:43:45 by incshin           #+#    #+#             */
/*   Updated: 2022/03/16 17:10:16 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	temp = (char *)malloc(s1_len);
	if (!temp)
		return (0);
	return ((char *)ft_memcpy(temp, s1, s1_len));
}