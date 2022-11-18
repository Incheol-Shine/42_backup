/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:51:34 by incshin           #+#    #+#             */
/*   Updated: 2022/11/19 00:53:50 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_operate(t_stack *a, t_stack *b, t_min *min)
{
	if (min->a_idx < a->size / 2 && min->b_idx < b->size / 2)
	{
		if (min->min > ft_max(min->a_idx, min->b_idx))
		{
			min->min = ft_max(min->a_idx, min->b_idx);
			a->idx = min->a_idx;
			b->idx = min->b_idx;
		}
	}
	else if (min->a_idx >= a->size / 2 && min->b_idx >= b->size / 2)
	{
		if (min->min > ft_max(a->size - min->a_idx, b->size - min->b_idx))
		{
			min->min = ft_max(a->size - min->a_idx, b->size - min->b_idx);
			a->idx = (a->size - min->a_idx) * -1;
			b->idx = (b->size - min->b_idx) * -1;
		}
	}
	else if (min->a_idx >= a->size / 2 && min->b_idx < b->size / 2)
	{
		if (min->min > ft_max(min->a_idx, min->b_idx))
		{
			min->min = ft_max(min->a_idx, min->b_idx);
			a->idx = min->a_idx;
			b->idx = min->b_idx;
		}
		if (min->min > ft_max(a->size - min->a_idx, b->size - min->b_idx))
		{
			min->min = ft_max(a->size - min->a_idx, b->size - min->b_idx);
			a->idx = (a->size - min->a_idx) * -1;
			b->idx = (b->size - min->b_idx) * -1;
		}
		if (min->min > (a->size - min->a_idx + min->b_idx))
		{
			min->min = a->size - min->a_idx + min->b_idx;
			a->idx = (a->size - min->a_idx) * -1;
			b->idx = min->b_idx;
		}
	}
	else if (min->a_idx < a->size / 2 && min->b_idx >= b->size / 2)
	{
		if (min->min > ft_max(min->a_idx, min->b_idx))
		{
			min->min = ft_max(min->a_idx, min->b_idx);
			a->idx = min->a_idx;
			b->idx = min->b_idx;
		}
		if (min->min > ft_max(a->size - min->a_idx, b->size - min->b_idx))
		{
			min->min = ft_max(a->size - min->a_idx, b->size - min->b_idx);
			a->idx = (a->size - min->a_idx) * -1;
			b->idx = (b->size - min->b_idx) * -1;
		}
		if (min->min > (min->a_idx + b->size - min->b_idx))
		{
			min->min = min->a_idx + b->size - min->b_idx;
			a->idx = min->a_idx;
			b->idx = (b->size - min->b_idx) * -1;
		}
	}
}
