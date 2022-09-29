/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:43:45 by incshin           #+#    #+#             */
/*   Updated: 2022/04/27 12:43:27 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	temp = (char *)malloc(s1_len + 1);
	if (!temp)
		return (0);
	ft_strlcpy(temp, s1, s1_len + 1);
	return (temp);
}
