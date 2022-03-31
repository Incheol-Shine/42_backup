/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:58:43 by incshin           #+#    #+#             */
/*   Updated: 2022/03/31 17:45:02 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	**temp;

	new = ft_lstnew(f(lst->content));
	if(!new)
		return (0);
	if (lst->next)
	{
		temp = (t_list **)malloc(sizeof(t_list *));
		*temp = ft_lstmap(lst->next, f, del);
		if (!*temp)
		{
			ft_lstdelone(new, del);
			free(temp);
			return (0);
		}
		ft_lstadd_front(temp, new);
	}
	return (new);
}
