/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:08:59 by incshin           #+#    #+#             */
/*   Updated: 2022/04/22 16:47:55 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*temp;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	temp = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!temp)
		return (0);
	ft_strlcat(temp, s1, len_s1 + 1);
	ft_strlcat(temp, s2, len_s1 + len_s2 + 1);
	return (temp);
}
