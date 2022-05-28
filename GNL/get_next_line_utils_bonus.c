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

#include "get_next_line_bonus.h"
#include <stdio.h>

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
        free(*lst);
        *lst = 0;
    }
}
