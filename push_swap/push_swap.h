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

#endif
