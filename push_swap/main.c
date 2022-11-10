#include "push_swap.h"

int	main(int argc, char *argv[])
{

	t_stack	*a;
	t_stack *b;

	if (argc < 2)
		exit(0);
	a = fill_stack(argc, argv);
	b = init_stack();
	show_stack(a);

	printf("pop pop pop : %d\n", stack_pop(a));
	printf("pop pop pop : %d\n", stack_pop(a));
	
	show_stack(a);
	return (0);
}
