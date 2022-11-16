#include "push_swap.h"

void	swap(t_stack *x)
{
	t_node	*temp;

	if (x->size < 2)
		return ;
	temp = x->top->next;
	x->top->next = temp->next;
	if (x->top->next)
		x->top->next->prev = x->top;
	temp->next = x->top;
	x->top->prev = temp;
	temp->prev = NULL;
	if (x->size == 2)
		x->bottom = x->top;
	x->top = temp;
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
	temp = x->top->next;
	x->top->prev = x->bottom;
	x->bottom->next = x->top;
	x->top->next = NULL;
	x->bottom = x->top;
	temp->prev = NULL;
	x->top = temp;
}

void	reverse_rotate(t_stack *x)
{
	t_node	*temp;

	if (x->size < 2)
		return ;
	temp = x->bottom->prev;
	x->bottom->next = x->top;
	x->top->prev = x->bottom;
	x->bottom->prev = NULL;
	x->top = x->bottom;
	temp->next = NULL;
	x->bottom = temp;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}
