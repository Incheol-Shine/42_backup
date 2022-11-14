#include "push_swap.h"

void	swap(t_stack *x)
{
	t_node	*temp;

	if (x->size < 2)
		return ;
	temp = x->head->next;
	x->head->next = temp->next;
	if (x->head->next)
		x->head->next->prev = x->head;
	temp->next = x->head;
	x->head->prev = temp;
	temp->prev = NULL;
	if (x->size == 2)
		x->tail = x->head;
	x->head = temp;
}

void	push_x_to_y(t_stack *x, t_stack *y)
{
	t_node	*x_top_node;

	if (!x->size)
		return ;
	x_top_node = new_node(stack_pop(x));
	stack_add(y, x_top_node);
}

void	rotate(t_stack *x)
{
	t_node	*temp;

	if (x->size < 2)
		return ;
	temp = x->head->next;
	x->head->prev = x->tail;
	x->tail->next = x->head;
	x->head->next = NULL;
	x->tail = x->head;
	temp->prev = NULL;
	x->head = temp;
}

void	reverse_rotate(t_stack *x)
{
	t_node	*temp;

	if (x->size < 2)
		return ;
	temp = x->tail->prev;
	x->tail->next = x->head;
	x->head->prev = x->tail;
	x->tail->prev = NULL;
	x->head = x->tail;
	temp->next = NULL;
	x->tail = temp;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}
