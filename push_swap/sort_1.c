/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:47 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 23:55:02 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wheel_sort(t_stack *a, t_stack *b, t_pivot pivot)
{
	if (a->size < 2)
		return ;
	else if (a->size == 2 && a->top->val > a->bottom->val)
		sa(a);
	else if (a->size == 3)
		three_elem_sort(a);
	else if (a->size > 3)
		many_elem_sort(a, b, pivot);
}

void	three_elem_sort(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->val;
	mid = a->top->next->val;
	bot = a->bottom->val;
	if (mid < top && top < bot)
		sa(a);
	else if (mid < bot && bot < top)
		ra(a);
	else if (bot < top && top < mid)
		rra(a);
	else if (bot < mid && mid < top)
	{
		sa(a);
		rra(a);
	}
	else if (top < bot && bot < mid)
	{
		sa(a);
		ra(a);
	}
}

void	many_elem_sort(t_stack *a, t_stack *b, t_pivot pivot)
{
	stack_divide_three(a, b, pivot);
	three_elem_sort(a);
	while (b->size)
	{
		get_min_rotate(a, b);
		rotate_same(a, b);
		rotate_a(a);
		pa(a, b);
	}
	a->idx = find_min_idx(a);
	rotate_a(a);
}

void	stack_divide_three(t_stack *a, t_stack *b, t_pivot pivot)
{
	int	temp;
	int	count;

	temp = a->size;
	count = 0;
	while (count < temp && a->size > 3)
	{
		if (a->top->val < pivot.one_third)
		{
			pb(a, b);
			rb(b);
		}
		else if (pivot.two_third < a->top->val)
			ra(a);
		else
			pb(a, b);
		count++;
	}
	while (a->size > 3)
		pb(a, b);
}

void	get_min_rotate(t_stack *a, t_stack *b)
{
	t_node		*b_node;
	t_min		min;

	b_node = b->top;
	min.b_idx = 0;
	min.min = MAX_INT;
	while (b_node)
	{
		min.a_idx = get_a_idx(a, b_node);
		min_operate(a, b, &min);
		b_node = b_node->next;
		min.b_idx++;
	}
}
