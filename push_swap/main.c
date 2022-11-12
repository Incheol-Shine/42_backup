#include "push_swap.h"

int	main(int argc, char *argv[])
{

	t_stack	*aa;
	t_stack *bb;

	if (argc < 2)
	{
		printf("main : arg error\n");
		return (0);
	}
	aa = fill_stack(argc, argv);
	bb = init_stack();
	show_stack(aa);
	printf("head: %p\n", aa->head);
	printf("tail: %p\n", aa->tail);
	swap(aa);
	show_stack(aa);
	printf("head: %p\n", aa->head);
	printf("tail: %p\n", aa->tail);
	rotate(aa);
	rotate(aa);
	show_stack(aa);
	printf("head: %p\n", aa->head);
	printf("tail: %p\n", aa->tail);
	reverse_rotate(aa);
	reverse_rotate(aa);
	reverse_rotate(aa);
	show_stack(aa);
	printf("head: %p\n", aa->head);
	printf("tail: %p\n", aa->tail);
	// show_stack(b);
	// show_stack(a);
	// push_x_to_y(a, b);
	// show_stack(a);
	// show_stack(b);
	// rotate(a);
	// show_stack(a);
	// reverse_rotate(a);
	// show_stack(a);
	// reverse_rotate(b);
	// show_stack(b);
	return (0);
}
