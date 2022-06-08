/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:51 by incshin           #+#    #+#             */
/*   Updated: 2022/06/02 15:39:34 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	lstclear(t_list **head, t_list **tail, ssize_t fd)
{
	t_list	*cur;
	t_list	*temp;

	if (!head)
		return ;
	if (!*head)
		return ;
	cur = *head;
	while (cur && fd != cur->fd)
		cur = cur->next;
	while (cur)
	{
		temp = cur->next;
		lstdel(cur, head, tail);
		cur = temp;
	}
}

ssize_t	get_size(t_list **head, t_list **tail, ssize_t fd)
{
	t_list	*temp;
	ssize_t	size;

	temp = *head;
	size = 0;
	while (1)
	{
		while (temp && (fd != temp->fd))
			temp = temp->next;
		if (!temp)
		{
			temp = lstnew(fd);
			if (!temp)
				return (-1);
			if (temp->ret_read == 0)
			{
				free(temp->buff);
				free(temp);
				return (size);
			}
			lstadd_back(head, tail, temp);
		}
		if (get_size_find_nl(&temp, &size))
			return (size);
	}
}

ssize_t	get_size_find_nl(t_list **temp, ssize_t *size)
{
	ssize_t	i;

	i = (*temp)->offset;
	while (i < (*temp)->ret_read)
	{
		if ((*temp)->buff[i] == '\n')
			return (++(*size));
		i++;
		(*size)++;
	}
	*temp = (*temp)->next;
	return (0);
}
