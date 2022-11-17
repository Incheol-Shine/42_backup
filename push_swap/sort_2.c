/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:57 by incshin           #+#    #+#             */
/*   Updated: 2022/11/17 20:24:27 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (l->val < b->top->val && b->top->val < r->val)
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

void	optimized_rotation(t_stack *a, int index)
{
	if (index < a->size / 2)
		while (index-- > 0)
			ra(a);
	else
	{
		index = a->size - index;
		while (index-- > 0)
			rra(a);
	}
}
