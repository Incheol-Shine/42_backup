/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:30:46 by incshin           #+#    #+#             */
/*   Updated: 2022/01/26 15:40:28 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
int 	ft_dest_len(int size, char **strs, char *sep);
int		ft_strcpy(char *s1, char *s2);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		j;
	int		dest_len;

	dest_len = ft_dest_len(size, strs, sep);
	dest = (char *)malloc(sizeof(char) * (dest_len + 1));
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (i < size)
	{
		j += ft_strcpy(dest + j, strs[i]);
		if (i != size - 1)
			j += ft_strcpy(dest + j, sep);
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int ft_dest_len(int size, char **strs, char *sep)
{
	int len;
	int i;
	
	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i != size - 1)
			len += ft_strlen(sep);
		i++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


int	ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (i);
}
