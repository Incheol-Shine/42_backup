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
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		stack->head->prev = new;
		new->next = stack->head;
		stack->head = new;
	}
	stack->size++;
}

int	stack_pop(t_stack *stack)
{
	int		val;
	t_node	*temp;

	// if (!stack->head)
	// {
	// 	printf("stack_pop : empty, this message should not pop\n");
	// 	exit(0);
	// }
	val = stack->head->val;
	temp = stack->head;
	if (stack->head->next)
		stack->head->next->prev = NULL;
	stack->head = stack->head->next;
	stack->size--;
	free(temp);
	if (!stack->size)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	return (val);
}

t_stack	*init_stack()
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		print_error_exit(MALLOC_ERR);
	stack->head = NULL;
	stack->tail = NULL;
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
	while (stack->head)
		stack_pop(stack);
	stack->head = NULL;
	stack->tail = NULL;
	// free(stack);
}

void	show_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		printf("val : %d, prev: %p, now: %p, next: %p\n", temp->val, temp->prev, temp, temp->next);
		temp = temp->next;
	}
	printf("stack's size = %d\n", stack->size);
}
