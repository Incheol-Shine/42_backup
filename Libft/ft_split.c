/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:13:16 by incshin           #+#    #+#             */
/*   Updated: 2022/03/28 11:04:08 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_arrsize(char const *s, char c);
static char	**ft_free(char **arr, int n);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	char	**temp;

	temp = (char **)calloc((ft_arrsize(s, c) + 1), sizeof(char *));
	if (!temp)
		return (0);
	i = 0;
	while (*s)
	{
		cnt = 0;
		while (s[cnt] && s[cnt] != c)
			cnt++;
		if (cnt)
		{
			temp[i] = (char *)malloc(cnt + 1);
			if (!temp[i])
				return (ft_free(temp, i));
			ft_strlcpy(temp[i++], s, cnt + 1);
			s += cnt;
		}
		else
			s++;
	}
	return (temp);
}

static int	ft_arrsize(char const *s, char c)
{
	int	size;

	size = 0;
	if (*s != 0 && *s != c)
		size = 1;
	while (*s)
	{
		if (*s == c)
		{
			if (*(s + 1) && *(s + 1) != c)
				size++;
		}
		s++;
	}
	return (size);
}

static char	**ft_free(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
