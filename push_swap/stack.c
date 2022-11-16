/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:45 by incshin           #+#    #+#             */
/*   Updated: 2022/11/16 17:18:46 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
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

	// if (!stack->top)
	// {
	// 	printf("stack_pop : empty, this message should not pop\n");
	// 	exit(0);
	// }
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

t_stack	*init_stack()
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		print_error_exit(MALLOC_ERR);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*fill_stack(int	size, int *numbers)
{
	t_stack *stack;
	t_node	*node;

	stack = init_stack();
	while (size-- > 0)
	{
		node = new_node(numbers[size]);
		stack_add(stack, node);
	}
	free(numbers);
	return stack;
}

void	clear_stack(t_stack *stack)
{
	while (stack->top)
		stack_pop(stack);
	stack->top = NULL;
	stack->bottom = NULL;
	// free(stack);
}

void	show_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		printf("val : %d, prev: %p, now: %p, next: %p\n", temp->val, temp->prev, temp, temp->next);
		temp = temp->next;
	}
	printf("stack's size = %d\n", stack->size);
}
