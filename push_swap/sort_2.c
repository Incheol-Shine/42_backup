/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:57 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 22:40:05 by incshin          ###   ########.fr       */
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

int	ft_max(int a, int b)
{
	int	max;

	max = a;
	if (a < b)
		max = b;
	return (max);
}

void	min_operate(t_stack *a, t_stack *b, int a_idx, int b_idx, int *min)
{
	if (a_idx < a->size / 2 && b_idx < b->size / 2)
	{
		if (*min > ft_max(a_idx, b_idx))
		{
			*min = ft_max(a_idx, b_idx);
			a->idx = a_idx;
			b->idx = b_idx;
		}
	}
	else if (a_idx >= a->size / 2 && b_idx >= b->size / 2)
	{
		if (*min > ft_max(a->size - a_idx, b->size - b_idx))
		{
			*min = ft_max(a->size - a_idx, b->size - b_idx);
			a->idx = (a->size - a_idx) * -1;
			b->idx = (b->size - b_idx) * -1;
		}
	}
	else if (a_idx >= a->size / 2 && b_idx < b->size / 2)
	{
		if (*min > ft_max(a_idx, b_idx))
		{
			*min = ft_max(a_idx, b_idx);
			a->idx = a_idx;
			b->idx = b_idx;
		}
		if (*min > ft_max(a->size - a_idx, b->size - b_idx))
		{
			*min = ft_max(a->size - a_idx, b->size - b_idx);
			a->idx = (a->size - a_idx) * -1;
			b->idx = (b->size - b_idx) * -1;
		}
		if (*min > (a->size - a_idx + b_idx))
		{
			*min = a->size - a_idx + b_idx;
			a->idx = (a->size - a_idx) * -1;
			b->idx = b_idx;
		}
	}
	else if (a_idx < a->size / 2 && b_idx >= b->size / 2)
	{
		if (*min > ft_max(a_idx, b_idx))
		{
			*min = ft_max(a_idx, b_idx);
			a->idx = a_idx;
			b->idx = b_idx;
		}
		if (*min > ft_max(a->size - a_idx, b->size - b_idx))
		{
			*min = ft_max(a->size - a_idx, b->size - b_idx);
			a->idx = (a->size - a_idx) * -1;
			b->idx = (b->size - b_idx) * -1;
		}
		if (*min > (a_idx + b->size - b_idx))
		{
			*min = a_idx + b->size - b_idx;
			a->idx = a_idx;
			b->idx = (b->size - b_idx) * -1;
		}
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
	min = MAX_INT;
	while (b_node)
	{
		a_idx = get_a_idx(a, b_node);
		// ft_printf("get_a_idx %d\n",a_idx);
		// ft_printf("now_a->idx %d\n",a->idx);
		min_operate(a, b, a_idx, b_idx, &min);
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

void	rotate_same(t_stack *a, t_stack *b)
{
	while (b->idx > 0)
	{
		rr(a, b);
		a->idx--;
		b->idx--;
	}
	while (b->idx < 0)
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

void	optimized_rotation(t_stack *a, t_stack *b)
{
	rotate_same(a, b);
	rotate_a(a);
}
