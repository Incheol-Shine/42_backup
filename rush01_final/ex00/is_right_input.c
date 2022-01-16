/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:29:37 by incshin           #+#    #+#             */
/*   Updated: 2022/01/16 18:30:00 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_right_input(char *str);
void	input2arr(char *str, int n);
int		ft_strlen(char *str);
int		g_edge[10][10];

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_right_input(char *str)
{
	int	str_len;
	int	n;
	int	i;

	str_len = ft_strlen(str);
	if ((str_len + 1) % 8 != 0)
		return (0);
	n = (str_len + 1) / 8;
	i = 0;
	while (str[i] != 0)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || '0' + n < str[i])
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	input2arr(str, n);
	return (n);
}

void	input2arr(char *str, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2 * n)
		{
			if (j % 2 == 0)
			{
				g_edge[i][j / 2] = str[(2 * n * i) + j] - '0';
			}
			j++;
		}
		i++;
	}
}
