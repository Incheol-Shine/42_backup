/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/05/26 19:03:34 by incshin          ###   ########.fr       */
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
	temp->buff = (char *)malloc(BUFF_SIZE);
	if (!temp->buff)
	{
		free(temp);
		return (0);
	}
	temp->rd_size = read(fd, temp->buff, BUFF_SIZE);
	if (temp->rd_size < 0)
	{
		free(temp->buff);
		free(temp);
		return (0);
	}
	return (temp);
}

ssize_t	get_size(t_list **head, ssize_t fd)
{
	t_list	*temp;
	ssize_t	size;
	ssize_t	i;

	temp = *head;
	size = 0;
	while (1)
	{
		while (temp && (fd != temp->fd))
			temp = temp->next;
		if (!temp)
		{
			temp = ft_lstnew(fd);
			if (!temp)
				return (-1);
			if (temp->rd_size == 0)
			{
				free(temp->buff);
				free(temp);
				temp = 0;
				return (size);
			}
			ft_lstadd_back(head, temp);
		}
		i = temp->offset;
		while (i < temp->rd_size)
		{
			if (temp->buff[i] == '\n')
				return (++size);
			i++;
			size++;
		}
		temp = temp->next;
	}
}

void	lstdel(t_list *node)
{
	t_list	*next_node;

	if (node->next)
	{
		next_node = node->next;
		node->fd = next_node->fd;
		node->offset = next_node->offset;
		node->rd_size = next_node->rd_size;
		free(node->buff);
		node->buff = next_node->buff;
		node->next = next_node->next;
		free(next_node);
	}
	else
		free(node);
}

char	*cpy_line(t_list **head, ssize_t size, ssize_t fd)
{
	char	*line;
	size_t	i;

	i = 0;
	line = (char *)malloc(size + 1);
	if (!line)
		return (0);
	line[size] = '\0';
	while (1)
	{
		while (fd != (*head)->fd)
			*head = (*head)->next;
		while ((*head)->offset < (size_t)(*head)->rd_size)
		{
			line[i++] = (*head)->buff[(*head)->offset++];
			if (!(--size))
				return (line);
		}
		lstdel(*head);
	}
}

char	*get_next_line(ssize_t fd)
{
	t_list			**head;
	static t_list	*backup;
	char			*line;
	ssize_t			size;

	head = (t_list **)malloc(sizeof(t_list *));
	if (!head)
		return (0);
	*head = backup;
	size = get_size(head, fd);
	if (size <= 0)
	{
		ft_lstclear(head, fd);
		free(head);
		return (0);
	}
	// printf("size: %zd\n", size);
	line = cpy_line(head, size, fd);
	if (!line)
	{
		// ft_lstclear(head);
		free(head);
		return (0);
	}
	// printf("backup1: %p\n",backup);
	if (!backup)
		backup = *head;
	// printf("backup2: %p\n",backup);
	free(head);
	return (line);
}
