/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:43:45 by incshin           #+#    #+#             */
/*   Updated: 2022/04/22 12:46:34 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	temp = (char *)ft_calloc(s1_len + 1, sizeof(char));
	if (!temp)
		return (0);
	return ((char *)ft_memcpy(temp, s1, s1_len));
}
