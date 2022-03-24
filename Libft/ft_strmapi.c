/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:32:50 by incshin           #+#    #+#             */
/*   Updated: 2022/03/21 20:25:18 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

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
