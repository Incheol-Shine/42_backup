/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:57 by incshin           #+#    #+#             */
/*   Updated: 2022/11/19 00:51:21 by incshin          ###   ########.fr       */
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

void	rotate_same(t_stack *a, t_stack *b)
{
	while (a->idx > 0 && b->idx > 0)
	{
		rr(a, b);
		a->idx--;
		b->idx--;
	}
	while (a->idx < 0 && b->idx < 0)
	{
		rrr(a, b);
		a->idx++;
		b->idx++;
	}
}

void	rotate_a(t_stack *a)
{
	while (a->idx)
	{
		if (a->idx > 0)
		{
			ra(a);
			a->idx--;
		}
		else
		{
			rra(a);
			a->idx++;
		}
	}
}

void	rotate_b(t_stack *b)
{
	while (b->idx)
	{
		if (b->idx > 0)
		{
			rb(b);
			b->idx--;
		}
		else
		{
			rrb(b);
			b->idx++;
		}
	}
}
