/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/05/11 18:30:24 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

#define BUFF_SIZE 5

char	*get_next_line(int fd)
{
	char		buff[BUFF_SIZE];
	int			rd_size;
	int			size;
	static char	*backup = "";
	char		*line;
	int			flag;

	if(0 > (rd_size = read(fd, buff, BUFF_SIZE)))
		return (0);
	size = 0;
	while (flag = buff[size] != '\n')
		size++;
	line = (char *)malloc(backup_size + size);
	ft_memcpy(line, buff, size);
	if (backup)
	{
		// backup 에 line 을 복사한다.
	}
	if (flag)
		backup = (static char *)malloc()
	else
}
