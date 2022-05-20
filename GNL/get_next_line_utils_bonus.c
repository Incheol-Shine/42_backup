/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:51 by incshin           #+#    #+#             */
/*   Updated: 2022/05/20 11:14:17 by incshin          ###   ########.fr       */
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

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;
	size_t		i;

	temp_dst = dst;
	temp_src = src;
	if (dst > src)
	{
		while (n--)
			temp_dst[n] = temp_src[n];
	}
	else if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}