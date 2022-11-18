/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:50 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 22:02:07 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *x)
{
	int	temp;

	if (x->size < 2)
		return ;
	temp = x->top->val;
	x->top->val = x->top->next->val;
	x->top->next->val = temp;
}

void	push_x_to_y(t_stack *x, t_stack *y)
{
	t_node	*x_top_node;

	if (!x->size)
		return ;
	x_top_node = new_node(stack_pop_top(x));
	stack_add_top(y, x_top_node);
}

void	revolve(t_stack *x)
{
	t_node	*x_bottom_node;

	if (x->size < 2)
		return ;
	x_bottom_node = new_node(stack_pop_top(x));
	stack_add_bottom(x, x_bottom_node);
}

void	reverse_revolve(t_stack *x)
{
	t_node	*x_top_node;

	if (x->size < 2)
		return ;
	x_top_node = new_node(stack_pop_bottom(x));
	stack_add_top(x, x_top_node);
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}
