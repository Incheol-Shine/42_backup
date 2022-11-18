/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:57 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 14:30:18 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_a_idx(t_stack *a, t_node *b_node)
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
			if (b_node->val < r->val)
				break ;
			else if (l->val < b_node->val)
				break ;
		}
		if (l->val < b_node->val && b_node->val < r->val)
			break ;
		l = r;
		r = r->next;
		count++;
	}
	return (count);
}

void	min_operate(t_stack *a, t_stack *b, int *min)
{
	int			a_idx;
	int			b_idx;

	if (a_idx < a->size / 2 && b_idx < b->size / 2)
	{
		min = 
	}
}

void	get_min_rotate(t_stack *a, t_stack *b)
{
	t_node		*b_node;
	int			a_idx;
	int			b_idx;
	int			min;
	
	b_node = b->top;
	b_idx = 0;
	min = 99999;
	while (b_node)
	{
		a_idx = get_a_idx(a, b_node);
		min_operate(a, b, min);
		b_node = b_node->next;
		b_idx++;
	}
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
