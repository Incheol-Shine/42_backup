/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:45 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 22:01:00 by incshin          ###   ########.fr       */
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
	stack->top = NULL;    // 이거 두개도 빼도 됨?
	stack->bottom = NULL; //
	free(stack);
}

void	show_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		ft_printf("val : %d, prev: %p, now: %p, next: %p\n", temp->val, temp->prev, temp, temp->next);
		temp = temp->next;
	}
	ft_printf("stack's size = %d\n", stack->size);
}
