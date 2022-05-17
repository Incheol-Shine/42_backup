/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/05/17 18:31:13 by incshin          ###   ########.fr       */
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
		return (0);
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

void	lstdel(t_list *node)
{
	t_list	*next_node;

	next_node = node->next;
	node->fd = next_node->fd;
	node->offset = next_node->offset;
	node->rd_size = next_node->rd_size;
	ft_memmove(node->buff, next_node->buff, BUFF_SIZE);
	node->next = next_node->next;
	free(next_node);
}

void	cpydel(char *line, t_list **head, size_t size)
{
	char	*temp;
	
	temp = line;
	while (*head)
	{
		while ((*head)->offset < (*head)->rd_size)
		{
			// printf("why segfault %zu, line: %s\n", size, temp);
			if (!(size--))
			{
				(*head)->offset++;
				return ;
			}
			*line++ = (*head)->buff[(*head)->offset++];
		}
		lstdel(*head);
	}
}

char	*get_next_line(ssize_t fd)
{
	t_list			**head;
	static t_list	*backup;
	t_list			*temp;
	t_list			*new;
	char			*line;
	size_t			size;
	int				i;

	head = (t_list **)malloc(sizeof(t_list *));
	if (!head)
		return (0);
	if (backup)
		*head = backup;
	else
	{
		new = ft_lstnew(fd);
		if (!new)
			return (0);
		ft_lstadd_back(head, new);
		backup = *head;
	}
	temp = *head;
	size = 0;
	while (1)
	{
		i = temp->offset;
		while (i < (temp->rd_size))
		{
			if ((temp->buff)[i++] == '\n')
			{
				line = (char *)malloc(size + 1);
				line[size] = '\0';
				cpydel(line, head, size);
				free(head);
				return (line);
			}
			size++;
		}
		if (!(temp->next))
		{
			new = ft_lstnew(fd);
			if (!new)
				return (0);
			ft_lstadd_back(head, new);
			temp = new;
		}
	}
	return (0);
}
