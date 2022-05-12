/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/05/12 18:31:18 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

t_list	*ft_lstnew(ssize_t fd)
{
	t_list	*temp;
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (0);
	temp->next = 0;
	temp->offset = 0;
	temp->fd = fd;
	temp->rd_size = read(fd, temp->buff, BUFF_SIZE);
	return (temp);
}

size_t	find(t_list **head)
{
	size_t	size;
	while (*head)
	{
		i = 0;
		while (i < BUFF_SIZE)
		{
			
		}
		*head = (*head)->next;
	}
	return (size);
}

char	*get_next_line(ssize_t fd)
{
	t_list			**head;
	static t_list	*backup;
	t_list			*new;
	char			*line;
	size_t			size;

	head = (t_list **)malloc(sizeof(t_list *));
	if (!head)
		return (0);
	if (backup)
		*head = backup;
	new = ft_lstnew(fd);
	if (!new)
		return (0);
	ft_lstadd_back(head, new);
	while (!(size = find(head)))
	{	
		new = ft_lstnew(fd);
		if (!new)
			return (0);
		ft_lstadd_back(head, new);
	}
	line = (char *)malloc(size + 1);
	line[size] = '\0';
	backup = (*head)->next;
	free(head);
	return (line);
}


