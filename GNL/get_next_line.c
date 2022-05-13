/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:30 by incshin           #+#    #+#             */
/*   Updated: 2022/05/13 15:56:03 by incshin          ###   ########.fr       */
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

size_t	read_find(ssize_t fd, t_list **head, size_t *size)
{
	size_t	i;
	t_list	*new;

	new = ft_lstnew(fd);
	if (!new)
		return (-1);
	ft_lstadd_back(head, new);
	i = 0;
	if (*head != new)
		i = (*head)->rd_size - (*head)->offset + 1;
	while ((new->offset) < BUFF_SIZE)
		if (new->buff[new->offset] == '\n')
		{
			*size += offset
			return (1);
		}
		(new->offset)++;
	return (0);
}

void	view(t_list *head)
{
	while (head)
	{
		printf("buff: %s..offset: %zu, rd_size: %zd\n", head->buff, head->offset, head->rd_size);
		head = head->next;
	}
}

char	*get_next_line(ssize_t fd)
{
	t_list			**head;
	static t_list	*backup;
	char			*line;
	size_t			*size;

	*size = 0;
	head = (t_list **)malloc(sizeof(t_list *));
	if (!head)
		return (0);
	if (backup)
		*head = backup;
	while (!(flag = read_find(fd, head, size)))
		*size += BUFF_SIZE;
	if (flag < 0)
		return (0);

	view(*head);
	printf("size : %zu\n", total_size);
	return (0);
	// line = (char *)malloc(total_size + 1);
	// line[total_size] = '\0';
	// backup = (*head)->next;
	// free(head);
	// return (line);
}


