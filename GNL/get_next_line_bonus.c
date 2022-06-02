/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/06/02 17:23:56 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"

t_list	*lstnew(ssize_t fd)
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
	temp->ret_read = read(fd, temp->buff, BUFF_SIZE);
	if (temp->ret_read < 0)
	{
		free(temp->buff);
		free(temp);
		return (0);
	}
	return (temp);
}

void	lstadd_back(t_list **head, t_list *new)
{
	t_list	*temp;

	if (!*head)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	lstdel(t_list *node)
{
	t_list	*next_node;

	next_node = (node)->next;
	(node)->fd = next_node->fd;
	(node)->offset = next_node->offset;
	(node)->ret_read = next_node->ret_read;
	free((node)->buff);
	(node)->buff = next_node->buff;
	(node)->next = next_node->next;
	free(next_node);
}

char	*cpy_line(t_list *head, ssize_t size, ssize_t fd)
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
		while (fd != (head)->fd)
			head = (head)->next;
		while ((head)->offset < (size_t)(head)->ret_read)
		{
			line[i++] = (head)->buff[(head)->offset++];
			if (!(--size))
				return (line);
		}
		lstdel(head);
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
	line = 0;
	if (size <= 0)
		lstclear(head, fd);
	else
	{
		line = cpy_line(*head, size, fd);
		if (!line)
			lstclear(head, fd);
	}
	backup = *head;
	free(head);
	return (line);
}
