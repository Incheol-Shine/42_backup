/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:45 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 14:26:23 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	stack_add(t_stack *stack, t_node *new)
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

int	stack_pop(t_stack *stack)
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
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	return (val);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		print_error_exit(MALLOC_ERR);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->idx = 0;
	return (stack);
}

t_stack	*fill_stack(int size, int *numbers)
{
	t_stack	*stack;
	t_node	*node;

	stack = init_stack();
	while (size-- > 0)
	{
		node = new_node(numbers[size]);
		stack_add(stack, node);
	}
	free(numbers);
	return (stack);
}

void	clear_stack(t_stack *stack)
{
	while (stack->top)
		stack_pop(stack);
	stack->top = NULL;
	stack->bottom = NULL;
	free(stack);
}
