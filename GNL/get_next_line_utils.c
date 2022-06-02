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

void	lstclear(t_list **lst, ssize_t fd)
{
	while (*lst)
	{
		if ((*lst)->fd == fd)
		{
			if ((*lst)->next)
				lstdel(*lst);
			else
			{
				free((*lst)->buff);
				free(*lst);
				*lst = 0;
				return ;
			}
		}
		else
		{
			lstclear2(*lst, fd);
			return ;
		}
	}
}

void	lstclear2(t_list *lst, ssize_t fd)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		if (next)
		{
			if (next->fd == fd)
			{
				lst->next = next->next;
				free(next->buff);
				free(next);
			}
			else
				lst = next;
		}
		else
			return ;
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
		temp = lstnew(fd);
		if (!temp)
			return (-1);
		if (temp->ret_read == 0)
		{
			free(temp->buff);
			free(temp);
			return (*size);
		}
		lstadd_back(head, temp);
	}
	return (get_size_part2(head, temp, fd, size));
}

ssize_t	get_size_part2(t_list **head, t_list *temp, ssize_t fd, ssize_t *size)
{
	ssize_t	i;

	i = temp->offset;
	while (i < temp->ret_read)
	{
		if (temp->buff[i] == '\n')
			return (++(*size));
		i++;
		(*size)++;
	}
	temp = temp->next;
	return (get_size_part1(head, temp, fd, size));
}
