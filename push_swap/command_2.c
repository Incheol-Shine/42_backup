#include "push_swap.h"

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	push_x_to_y(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push_x_to_y(a, b);
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
