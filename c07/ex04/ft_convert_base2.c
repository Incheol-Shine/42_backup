/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:13:21 by incshin           #+#    #+#             */
/*   Updated: 2022/01/27 13:13:23 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_savenbr(char *ptr, int nbr, int size, char *base_to);
int		ft_nbrlen(int nbr, int base_n);
char	*ft_itoa(int nbr, char *base);
int		ft_strlen(char *str);

char	*ft_itoa(int nbr, char *base)
{
	char	*ptr;
	int		ptr_len;
	int		base_n;

	base_n = ft_strlen(base);
	ptr_len = ft_nbrlen(nbr, base_n);
	ptr = (char *)malloc(sizeof(char) * (ptr_len + 2));
	if (!ptr)
		return (0);
	ptr[ptr_len + 1] = '\0';
	ft_savenbr(ptr + 1, nbr, ptr_len + 1, base);
	if (nbr < 0)
	{
		ptr[0] = '-';
		return (ptr);
	}
	return (ptr + 1);
}

int	ft_nbrlen(int nbr, int base_n)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= base_n;
		i++;
	}
	return (i);
}

void	ft_savenbr(char *ptr, int nbr, int size, char *base_to)
{
	int	i;
	int	sign;
	int	base_n;

	i = 0;
	sign = 1;
	base_n = ft_strlen(base_to);
	if (nbr < 0)
		sign = -1;
	while (nbr / base_n)
	{
		ptr[size - 1 - i] = base_to[sign * (nbr % base_n)];
		nbr /= base_n;
		i++;
	}
	ptr[0] = base_to[nbr * sign];
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
