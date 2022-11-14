#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdlib.h>
# include 	<unistd.h>
# include	"libft/libft.h"
# define	ARG_ERR			0
# define	MALLOC_ERR		1
# define	ATOI_ERR		2
# define	ALREADY_SORTED	3

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				val;
}				t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	unsigned int	size;
}				t_stack;

int		*check_overlap(int size, char *argv[]);
int 	*str_to_int_arr(int size, char *argv[]);
int		push_swap_atoi(const char *str);
t_stack	*init_stack();
t_stack	*fill_stack(int	size, int num_arr_str[]);
void	stack_add(t_stack *stack, t_node *new);
t_node	*new_node(int num);
void	show_stack(t_stack *stack);
int		stack_pop(t_stack *stack);
void	clear_stack(t_stack *stack);
void	swap(t_stack *x);
void	push_x_to_y(t_stack *x, t_stack *y);
void	rotate(t_stack *x);
void	reverse_rotate(t_stack *x);
void	print_error_exit(int err_no);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	wheel_sort(t_stack *a, t_stack *b);
#endif
