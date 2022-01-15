/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemilee <jaemilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:27:32 by jaemilee          #+#    #+#             */
/*   Updated: 2022/01/15 18:08:13 by jaemilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	len_of_str(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	make_arry(char *str, char *arr)
{
	int i;
	int j;
	char *m_arr;

	i = 0;
	m_arr = arr;
	while(str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			*m_arr = str[i];
			m_arr++;
		}
		i++;
	}
}

void DFS_bord(char **bord, int n, int a, int b)
{
	int	i;
	int	j;
	if (n == b)
	{
		return;
	}

	i = a;
	while (i < n)
	{
		j = a;
		while ( j < n)
		{
			bord[i][j] = (j + 1) + '0';
			j++;
		}
		i++;
	}
}

int	main(void)
{
	char	str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int		len;
	len = len_of_str(str);

	char	arr[len];
	int		len_arr;
	int		n;
	make_arry(str, arr);
	n = len_of_str(arr) / 4;

	char	**bord;
	bord = (char**)malloc(sizeof(char*)*n);
	int i = 0;
	while (i < n)
	{
		bord[i] = (char*)malloc(sizeof(char)*n);
		i++;
	}
	
	DFS_bord(bord, n, 0, 0);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%c", bord[i][j]);
		}
		printf("\n");
	}
}
