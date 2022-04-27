/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:51:52 by incshin           #+#    #+#             */
/*   Updated: 2022/04/27 11:37:41 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay_len;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	hay_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	j = 0;
	if (needle_len == 0)
		return ((char *)haystack);
	while (0 <= i && i + needle_len <= hay_len && i + needle_len <= len)
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		}
		i = i - j + 1;
		j = 0;
	}
	return (0);
}
