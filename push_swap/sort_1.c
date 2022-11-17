/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:47 by incshin           #+#    #+#             */
/*   Updated: 2022/11/17 20:20:25 by incshin          ###   ########.fr       */
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
		optimized_rotation(a, find_place_b_top(a, b));
		pa(a, b);
	}
	optimized_rotation(a, find_min_idx(a));
	return ;
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
			ra(a);
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
