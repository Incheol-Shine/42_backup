#include	<stdio.h>
#include	"push_swap.h"

int	main(int argc, char *argv[])
{

	t_stack	*aa;
	t_stack *bb;
	int		*numbers;

	if (argc < 2)
		print_error_exit(ARG_ERR);
	numbers = check_overlap(argc - 1, argv);
	aa = fill_stack(argc - 1, numbers);
	bb = init_stack();
	wheel_sort(aa, bb);
	return (0);
}



	// show_stack(aa);
	// show_stack(bb);
	// printf("head: %p\n", aa->head);
	// printf("tail: %p\n", aa->tail);
	// swap(aa);
	// show_stack(aa);
	// printf("head: %p\n", aa->head);
	// printf("tail: %p\n", aa->tail);
	// rotate(aa);
	// rotate(aa);
	// show_stack(aa);
	// printf("head: %p\n", aa->head);
	// printf("tail: %p\n", aa->tail);
	// reverse_rotate(aa);
	// reverse_rotate(aa);
	// reverse_rotate(aa);
	// show_stack(aa);
	// printf("head: %p\n", aa->head);
	// printf("tail: %p\n", aa->tail);

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
	// clear_stack(aa);
	// printf("head: %p\n", aa->head);
	// printf("tail: %p\n", aa->tail);
	// show_stack(aa);
	// clear_stack(bb);
	// show_stack(bb);