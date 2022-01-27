/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:12:55 by incshin           #+#    #+#             */
/*   Updated: 2022/01/27 13:12:57 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		idx_base(char c, char *base);
int		ft_strlen(char *str);
char	*ft_itoa(int nbr, char *base);
int		is_right_base(char *base);
int		is_exist_same_char(char *base, int size);
int		ft_atoi_base(char *nbr, char *base_from);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nbr_mk2;

	if (!(is_right_base(base_from) && is_right_base(base_to)))
		return (0);
	nbr_mk2 = ft_atoi_base(nbr, base_from);
	return (ft_itoa(nbr_mk2, base_to));
}

int	ft_atoi_base(char *nbr, char *base_from)
{
	int	n;
	int	sign;
	int	i;
	int	idx;

	i = 0;
	while (nbr[i] == ' ' || (9 <= nbr[i] && nbr[i] <= 13))
		i++;
	sign = 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	n = 0;
	while (nbr[i])
	{
		idx = idx_base(nbr[i], base_from);
		if (idx < 0)
			return (0);
		n = (n * ft_strlen(base_from)) + idx;
		i++;
	}
	return (sign * n);
}

int	is_right_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	if (is_exist_same_char(base, i))
		return (0);
	return (i);
}

int	is_exist_same_char(char *base, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	idx_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}
