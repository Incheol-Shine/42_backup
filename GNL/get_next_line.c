/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/05/23 17:16:35 by incshin          ###   ########.fr       */
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
	if (temp->rd_size < 0)
	{
		free(temp);
		return (0);
	}
	return (temp);
}

void	view(t_list *head)
{
	while (head)
	{
		printf("buff: %s/, offset: %zu, rd_size: %zd, fd: %zd\n", head->buff, head->offset, head->rd_size, head->fd);
		head = head->next;
	}
	printf("\n");
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
			ft_lstadd_back(head, temp);
			if (temp->rd_size == 0)
				return (size);
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

int	lstdel(t_list *node)
{
	t_list	*next_node;

	if (node->next)
	{
		next_node = node->next;
		node->fd = next_node->fd;
		node->offset = next_node->offset;
		node->rd_size = next_node->rd_size;
		ft_memmove(node->buff, next_node->buff, BUFF_SIZE);
		node->next = next_node->next;
		free(next_node);
		return (0);
	}
	else
	{
		// free(node);
		return (1);
	}
}

char	*cpy_line(t_list **head, size_t size, ssize_t fd)
{
	char	*line;
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	line = (char *)malloc(size + 1);
	if (!line)
		return (0);
	line[size] = '\0';
	while ((!flag) && *head)
	{
		while (fd != (*head)->fd)
			*head = (*head)->next;
		while ((*head)->offset < (size_t)(*head)->rd_size)
		{
			if (!(size--))
				return (line);
			line[i++] = (*head)->buff[(*head)->offset++];
		}
		flag = lstdel(*head);
		// printf("%p, rd_size: %zd, offset: %zd, %s\n",(*head)->next, (*head)->rd_size, (*head)->offset, (*head)->buff);
	}
	return (line);
}

char	*get_next_line(ssize_t fd)
{
	t_list			**head;
	static t_list	*backup;
	char			*line;
	size_t			size;

	head = (t_list **)malloc(sizeof(t_list *));
	if (!head)
		return (0);
	if (backup)
		*head = backup;
	size = get_size(head, fd);
	// printf("head_buff: %s\n", (*head)->buff);
	if (size <= 0)
		return (0);
	// printf("size: %zd\n", size);
	line = cpy_line(head, size, fd);
	if (!line)
		return (0);
	if (!backup)
		backup = *head;
	return (line);
}
