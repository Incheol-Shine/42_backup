/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:51:34 by incshin           #+#    #+#             */
/*   Updated: 2022/11/19 01:13:24 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_operate(t_stack *a, t_stack *b, t_min *min)
{
	if (min->a_idx < a->size / 2 && min->b_idx < b->size / 2)
		a_b_both_small(a, b, min);
	else if (min->a_idx >= a->size / 2 && min->b_idx >= b->size / 2)
		a_b_both_big(a, b, min);
	else if (min->a_idx >= a->size / 2 && min->b_idx < b->size / 2)
	{
		a_b_both_small(a, b, min);
		a_b_both_big(a, b, min);
		a_big_b_small(a, b, min);
	}
	else if (min->a_idx < a->size / 2 && min->b_idx >= b->size / 2)
	{
		a_b_both_small(a, b, min);
		a_b_both_big(a, b, min);
		a_small_b_big(a, b, min);
	}
}

void	a_b_both_small(t_stack *a, t_stack *b, t_min *min)
{
	if (min->min > ft_max(min->a_idx, min->b_idx))
	{
		min->min = ft_max(min->a_idx, min->b_idx);
		a->idx = min->a_idx;
		b->idx = min->b_idx;
	}
}

void	a_b_both_big(t_stack *a, t_stack *b, t_min *min)
{
	if (min->min > ft_max(a->size - min->a_idx, b->size - min->b_idx))
	{
		min->min = ft_max(a->size - min->a_idx, b->size - min->b_idx);
		a->idx = (a->size - min->a_idx) * -1;
		b->idx = (b->size - min->b_idx) * -1;
	}
}

void	a_big_b_small(t_stack *a, t_stack *b, t_min *min)
{
	if (min->min > (a->size - min->a_idx + min->b_idx))
	{
		min->min = a->size - min->a_idx + min->b_idx;
		a->idx = (a->size - min->a_idx) * -1;
		b->idx = min->b_idx;
	}
}

void	a_small_b_big(t_stack *a, t_stack *b, t_min *min)
{
	if (min->min > (min->a_idx + b->size - min->b_idx))
	{
		min->min = min->a_idx + b->size - min->b_idx;
		a->idx = min->a_idx;
		b->idx = (b->size - min->b_idx) * -1;
	}
}
