/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:15:50 by incshin           #+#    #+#             */
/*   Updated: 2022/03/26 12:15:50 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		s_len;
	int		i;
	char	*temp;

	i = 0;
	s_len = ft_strlen(s);
	temp = (char *)malloc(s_len + 1);
	if (!temp)
		return (0);
	while (i < s_len)
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	return (temp);
}
