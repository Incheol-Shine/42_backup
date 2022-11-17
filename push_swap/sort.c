/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:47 by incshin           #+#    #+#             */
/*   Updated: 2022/11/17 13:36:55 by incshin          ###   ########.fr       */
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
	int mid;
	int bot;

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

void stack_divide_three(t_stack *a, t_stack *b, t_pivot pivot)
{
	int	temp;
	int count;

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

int	find_place_b_top(t_stack *a, t_stack *b)
{
	t_node	*l;
	t_node	*r;
	int		count;

	l = a->bottom;
	r = a->top;
	count = 0;
	while (r)
	{
		if (l->val > r->val)
		{
			if (b->top->val < r->val)
				break ;
			else if (l->val < b->top->val)
				break ;
		}
		if(l->val < b->top->val && b->top->val < r->val)
			break ;
		l = r;
		r = r->next;
		count++;
	}
	return (count);
}

int	find_min_idx(t_stack *a)
{
	t_node	*l;
	t_node	*r;
	int		count;

	l = a->bottom;
	r = a->top;
	count = 0;
	while (r && !(l->val > r->val))
	{
		l = r;
		r = r->next;
		count++;
	}
	return (count);
}

void	many_elem_sort(t_stack *a, t_stack *b, t_pivot pivot)
{
	int	index;

	stack_divide_three(a, b, pivot);
	three_elem_sort(a);
	while (b->size)
	{
		index = find_place_b_top(a, b);
		// ft_printf("idx : %d or %d \n", index, a->size - index);
		if (index < a->size / 2)
			while (index-- > 0)
				ra(a);
		else
			index = a->size - index;
			while (index-- > 0)
				rra(a);
		pa(a, b);
	}
	index = find_min_idx(a);
	// ft_printf("idx2 : %d or %d \n", index, a->size - index);
	if (index <= a->size / 2)
			while (index-- > 0)
				ra(a);
		else
			index = a->size - index;
			while (index-- > 0)
				rra(a);
	return ;
}


