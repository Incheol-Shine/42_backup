/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/05/16 20:13:10 by incshin          ###   ########.fr       */
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
		printf("buff: %s..offset: %zu, rd_size: %zd\n", head->buff, head->offset, head->rd_size);
		head = head->next;
	}
}

void	cpyfree(char *line, t_list **head)
{

}

char	*get_next_line(ssize_t fd)
{
	t_list			**head;
	static t_list	*backup;
	t_list			*temp;
	t_list			*new;
	char			*line;
	size_t			size[1];

	*size = 0;
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
	}
	temp = *head;
	while (1)
	{
		while ((temp->offset) < BUFF_SIZE)
		{
			if ((temp->buff)[(temp->offset)++] == '\n')
			{
				line = (char *)malloc((*size) + 1);
				line[*size] = '\0';
				cpyfree(char *line, t_list **head);
				backup = temp;
				free(head);
				return (line);
			}
			(*size)++;
		}
		new = ft_lstnew(fd);
		if (!new)
			return (0);
		ft_lstadd_back(head, new);
		temp = new;
	}
	return (0);
}
