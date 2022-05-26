/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:51 by incshin           #+#    #+#             */
/*   Updated: 2022/05/17 18:21:43 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	if (!*head)
		*head = new;
	else
		ft_lstlast(*head)->next = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*cur;

	if (!lst)
		return ;
	while (*lst)
	{
		cur = (*lst)->next;
		free((*lst)->buff);
		free(*lst);
		*lst = cur;
	}
}

