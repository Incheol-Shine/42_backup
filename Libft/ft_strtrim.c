/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:25:32 by incshin           #+#    #+#             */
/*   Updated: 2022/04/29 16:05:51 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*temp;

	left = 0;
	right = ft_strlen(s1) - 1;
	while (ft_isinset(s1[left], set) && s1[left])
		left++;
	while (ft_isinset(s1[right], set) && left < right)
		right--;
	temp = (char *)ft_calloc(right - left + 2, sizeof(char));
	if (!temp)
		return (0);
	ft_strlcpy(temp, s1 + left, right - left + 2);
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
