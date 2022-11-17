/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:33:21 by incshin           #+#    #+#             */
/*   Updated: 2022/11/17 20:35:47 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_exit(int err_no)
{
	if (err_no == ARG_ERR)
		ft_printf("arg error\n");
	else if (err_no == MALLOC_ERR)
		ft_printf("malloc error\n");
	else if (err_no == ATOI_ERR)
		ft_printf("atoi error : not int type\n");
	exit(0);
}

t_node	*new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		print_error_exit(MALLOC_ERR);
	node->next = NULL;
	node->prev = NULL;
	node->val = num;
	return (node);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
