/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:45 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 23:28:48 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_node	*new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		print_error_exit(MALLOC_ERR);
	node->next = NULL;
	node->prev = NULL;
	node->val = num;
	return (node);
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
		stack_add_top(stack, node);
	}
	free(numbers);
	return (stack);
}

void	clear_stack(t_stack *stack)
{
	while (stack->top)
		stack_pop_top(stack);
	free(stack);
}
