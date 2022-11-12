#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include	"libft/libft.h"

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

t_stack	*init_stack();
t_stack	*fill_stack(int	size, char *num_arr_str[]);
void	stack_add(t_stack *stack, t_node *new);
t_node	*new_node(int num);
void	show_stack(t_stack *stack);
int		stack_pop(t_stack *stack);
int		push_swap_atoi(const char *str);
void	swap(t_stack *x);
void	push_x_to_y(t_stack *x, t_stack *y);
void	rotate(t_stack *x);
void	reverse_rotate(t_stack *x);

#endif
