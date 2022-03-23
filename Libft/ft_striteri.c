/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:26:05 by incshin           #+#    #+#             */
/*   Updated: 2022/03/23 10:27:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	printf("s: %s\n",s);
	while (s[i])
	{
		printf("i: %d, s[i]: %c\n", i, s[i]);
		f(i, s + i);
		printf("after - i: %d, s[i]: %c\n", i, s[i]);
		i++;
	}
}
