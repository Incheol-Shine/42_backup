/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:46:27 by incshin           #+#    #+#             */
/*   Updated: 2022/01/13 17:27:51 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src[i] == 0)
		{
			dest[i] = src[i];
			break ;
		}
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

int	main(void)
{
	unsigned int	n;
	char src[] = "ImaB";
	char dst[30] = "1234567891234567890012";
	//int size = sizeof(src) / sizeof(src[0]);

	n = 10;
	printf("before : %s\n", dst);
	printf("Call strncpy : %s\n", ft_strncpy(dst, src, n));
	//dst[size-1] = 'z';
	//dst[size] = 'z';
	printf("after : %s\n", dst);
}
