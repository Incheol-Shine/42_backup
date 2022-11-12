#include "push_swap.h"

t_node	*new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		printf("new_node : malloc error\n");
		exit(0);
	}
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

	if (!stack->head)
	{
		printf("stack_pop : empty\n");
		exit(0);
	}
	val = stack->head->val;
	temp = stack->head;
	stack->head->next->prev = NULL;
	stack->head = stack->head->next;
	stack->size--;
	free(temp);

	return (val);
}

int	push_swap_atoi(const char *str)
{
	int	i;
	int	sign;
	int	answer;

	i = 0;
	sign = (str[i] != '-') * 2 - 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	answer = 0;
	while (ft_isdigit(str[i]))
	{
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] && (!ft_isdigit(str[i])))
	{
		printf("atoi : not digit number :%d.%s\n", str[i], str);
		exit(0);
	}
	return (sign * answer);
}

t_stack	*fill_stack(int	size, char *num_arr_str[])
{
	t_stack *stack;
	t_node	*node;

	stack = init_stack();
	while (size-- > 1)
	{
		node = new_node(push_swap_atoi(num_arr_str[size]));
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
	{
		printf("init_stack : malloc error\n");
		exit (0);
	}
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
		printf("val : %d, prev: %p, now: %p, next: %p\n", temp->val, temp->prev, temp, temp->next);
		temp = temp->next;
	}
	printf("stack's size = %d\n", stack->size);
}