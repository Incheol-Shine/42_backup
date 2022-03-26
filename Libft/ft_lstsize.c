/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:12:48 by incshin           #+#    #+#             */
/*   Updated: 2022/03/26 12:12:49 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;
	t_list	*temp;

	count = 0;
	temp = lst;
	while (temp)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}
