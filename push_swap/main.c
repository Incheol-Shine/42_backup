#include "push_swap.h"

int	main(int argc, char *argv[])
{

	t_stack	*a;
	t_stack *b;

	if (argc < 2)
	{
		printf("main : arg error\n");
		return (0);
	}
	a = fill_stack(argc, argv);
	b = init_stack();
	show_stack(a);
	swap(a);
	show_stack(a);
	push_x_to_y(a, b);
	show_stack(a);
	show_stack(b);
	rotate(a);
	show_stack(a);
	reverse_rotate(a);
	show_stack(a);
	reverse_rotate(b);
	show_stack(b);
	return (0);
}
