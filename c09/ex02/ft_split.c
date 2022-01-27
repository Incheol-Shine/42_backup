/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:13:35 by incshin           #+#    #+#             */
/*   Updated: 2022/01/27 13:14:11 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);
int		is_sep(char c, char *charset);
int		ft_destsize(char *str, char *charset);
void	ft_strncpy(char *dest, char *src, int n);

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		cnt;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (ft_destsize(str, charset) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		cnt = 0;
		while (str[i + cnt] && !is_sep(str[i + cnt], charset))
			cnt++;
		if (cnt)
		{
			dest[j] = (char *)malloc(sizeof(char) * (cnt + 1));
			ft_strncpy(dest[j], str + i, cnt);
			j++;
		}
		else
			i++;
		i += cnt;
	}
	dest[j] = NULL;
	return (dest);
}

int	ft_destsize(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
		{
			if (str[i + 1] && !(is_sep(str[i + 1], charset)))
				size ++;
		}
		else if (i == 0)
			size ++;
		i++;
	}
	return (size);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
