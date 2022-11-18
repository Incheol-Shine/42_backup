/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:06:36 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 23:20:14 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	stack_add_top(t_stack *stack, t_node *new)
{
	if (!stack->top)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->top->prev = new;
		new->next = stack->top;
		stack->top = new;
	}
	stack->size++;
}

void	stack_add_bottom(t_stack *stack, t_node *new)
{
	if (!stack->bottom)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->next = new;
		new->prev = stack->bottom;
		stack->bottom = new;
	}
	stack->size++;
}

int	stack_pop_top(t_stack *stack)
{
	int		val;
	t_node	*temp;

	val = stack->top->val;
	temp = stack->top;
	if (stack->top->next)
		stack->top->next->prev = NULL;
	stack->top = stack->top->next;
	stack->size--;
	free(temp);
	if (!stack->size)
		stack->bottom = NULL;
	return (val);
}

int	stack_pop_bottom(t_stack *stack)
{
	int		val;
	t_node	*temp;

	val = stack->bottom->val;
	temp = stack->bottom;
	if (stack->bottom->prev)
		stack->bottom->prev->next = NULL;
	stack->bottom = stack->bottom->prev;
	stack->size--;
	free(temp);
	if (!stack->size)
		stack->top = NULL;
	return (val);
}
