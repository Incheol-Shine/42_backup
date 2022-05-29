/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:51 by incshin           #+#    #+#             */
/*   Updated: 2022/05/26 19:08:57 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	lstdel(t_list *node)
{
	t_list	*next_node;

	next_node = (node)->next;
	(node)->fd = next_node->fd;
	(node)->offset = next_node->offset;
	(node)->rd_size = next_node->rd_size;
	free((node)->buff);
	(node)->buff = next_node->buff;
	(node)->next = next_node->next;
	free(next_node);
}

void	ft_lstclear(t_list **lst, ssize_t fd, int depth)
{
	if (!lst)
		return ;
	if (!*lst)
		return ;
	if ((*lst)->next)
	{
		ft_lstclear(&((*lst)->next), fd, depth + 1);
		if (fd == (*lst)->fd)
			lstdel(*lst);
	}
	if (fd == (*lst)->fd && depth == 0)
	{
		free((*lst)->buff);
		free(*lst);
		*lst = 0;
	}
}

ssize_t	get_size(t_list **head, ssize_t fd)
{
	t_list	*temp;
	ssize_t	i;
	ssize_t	*size;

	i = 0;
	temp = *head;
	size = &i;
	return (get_size_part1(head, temp, fd, size));
}

ssize_t	get_size_part1(t_list **head, t_list *temp, ssize_t fd, ssize_t *size)
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
			return (*size);
		}
		ft_lstadd_back(head, temp);
	}
	return (get_size_part2(head, temp, fd, size));
}

ssize_t	get_size_part2(t_list **head, t_list *temp, ssize_t fd, ssize_t *size)
{
	ssize_t	i;

	i = temp->offset;
	while (i < temp->rd_size)
	{
		if (temp->buff[i] == '\n')
			return (++(*size));
		i++;
		(*size)++;
	}
	temp = temp->next;
	return (get_size_part1(head, temp, fd, size));
}
