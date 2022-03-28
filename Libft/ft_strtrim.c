/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:25:32 by incshin           #+#    #+#             */
/*   Updated: 2022/03/28 11:04:56 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isinset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*temp;

	left = 0;
	right = ft_strlen(s1) - 1;
	while (ft_isinset(s1[left], set))
		left++;
	while (ft_isinset(s1[right], set))
		right--;
	temp = (char *)malloc(right - left + 2);
	if (!temp)
		return (0);
	ft_strlcat(temp, s1 + left, right - left + 2);
	return (temp);
}

static int	ft_isinset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
