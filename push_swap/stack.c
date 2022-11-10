#include "push_swap.h"

t_node	*new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit (0);
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
		new->next = stack->head;
		stack->head = new;
	}
}

int	stack_pop(t_stack *stack)
{
	int		val;
	t_node	*temp;

	if (!stack->head)
		exit(0);
	val = stack->head->val;
	temp = stack->head;
	stack->head = stack->head->next;
	stack->size--;
	free(temp);

	return (val);
}


t_stack	*fill_stack(int	size, char *num_arr_str[])
{
	t_stack *stack;
	t_node	*node;

	stack = init_stack();
	stack->size = size - 1;
	while (size-- != 1)
	{
		node = new_node(ft_atoi(num_arr_str[size]));
		stack_add(stack, node);
	}
	return stack;
}

// exit 하는 함수를 구현해야 함
t_stack	*init_stack()
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit (0);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	show_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		printf("val : %d, next: %p\n", temp->val, temp->next);
		temp = temp->next;
	}
	printf("stack's size = %d\n", stack->size);
}