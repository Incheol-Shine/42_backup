/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:51:52 by incshin           #+#    #+#             */
/*   Updated: 2022/03/14 18:16:03 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t	str_len;
    size_t	find_len;
    size_t	i;
    size_t	j;
    
    hay_len = ft_strlen(haystack);
    needle_len = ft_strlen(needle;
    i = 0;
    j = 0;
    while (0 <= i && i <= str_len - find_len && i < len)
    {
        while (haystack[i] == needle[j])
        {
            i++;
            j++;
            if (needle[j] == '\0')
                return (&haystack[i - j]);
        }
        i = i - j + 1;
        j = 0;
    }
    return ('\0');
}