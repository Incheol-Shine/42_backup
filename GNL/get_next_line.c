/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/06/07 12:14:57 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(ssize_t fd)
{
	t_list			*head;
	t_list			*tail;
	static t_backup	backup;
	char			*line;
	ssize_t			size;

	head = backup.head;
	tail = backup.tail;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	size = get_size(&head, &tail, fd);
	line = 0;
	if (size <= 0)
		lstclear(&head, &tail, fd);
	else
	{
		line = cpy_line(head, tail, size, fd);
		if (!line)
			lstclear(&head, &tail, fd);
	}
	backup.head = head;
	backup.tail = tail;
	return (line);
}

t_list	*lstnew(ssize_t fd)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (0);
	temp->next = 0;
	temp->prev = 0;
	temp->offset = 0;
	temp->fd = fd;
	temp->buff = (char *)malloc(BUFFER_SIZE);
	if (!temp->buff)
	{
		free(temp);
		return (0);
	}
	temp->ret_read = read(fd, temp->buff, BUFFER_SIZE);
	if (temp->ret_read < 0)
	{
		free(temp->buff);
		free(temp);
		return (0);
	}
	return (temp);
}

void	lstadd_back(t_list **head, t_list **tail, t_list *new)
{
	if (!*head)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
	}
}

void	lstdel(t_list *cur, t_list **phead, t_list **ptail)
{
	if (!cur)
		return ;
	if (cur->prev)
		cur->prev->next = cur->next;
	else
		*phead = cur->next;
	if (cur->next)
		cur->next->prev = cur->prev;
	else
		*ptail = cur->prev;
	cur->prev = 0;
	cur->next = 0;
	free(cur->buff);
	free(cur);
}

char	*cpy_line(t_list *head, t_list *tail, ssize_t size, ssize_t fd)
{
	char	*line;
	size_t	i;
	t_list	*cur;
	t_list	*temp;

	i = 0;
	cur = head;
	line = (char *)malloc(size + 1);
	if (!line)
		return (0);
	line[size] = '\0';
	while (1)
	{
		while (fd != (cur)->fd)
			cur = (cur)->next;
		while ((cur)->offset < (size_t)(cur)->ret_read)
		{
			line[i++] = (cur)->buff[(cur)->offset++];
			if (!(--size))
				return (line);
		}
		temp = cur->next;
		lstdel(cur, &head, &tail);
		cur = temp;
	}
}
