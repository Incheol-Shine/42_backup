/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:19:06 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 19:11:32 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define ARG_ERR		-1
# define DUP_ERR		0
# define MALLOC_ERR		1
# define ATOI_ERR		2
# define ALREADY_SORTED	3
# define MAX_INT		2147483647

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				val;
}				t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
	int				idx;
}				t_stack;

typedef struct s_pivot
{
	int	one_third;
	int	two_third;
}				t_pivot;

void	check_overlap_pivot(int size, int *numbers, t_pivot *pivot);
int		*str_to_int_arr(int size, char *argv[]);
int		push_swap_atoi(const char *str);
t_stack	*init_stack(void);
t_stack	*fill_stack(int size, int num_arr_str[]);
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
void	ft_swap(int *a, int *b);
void	wheel_sort(t_stack *a, t_stack *b, t_pivot pivot);
void	three_elem_sort(t_stack *a);
void	many_elem_sort(t_stack *a, t_stack *b, t_pivot pivot);
void	stack_divide_three(t_stack *a, t_stack *b, t_pivot pivot);
int		get_a_idx(t_stack *a, t_node *b_node);
int		find_min_idx(t_stack *a);
void	check_already_sort(int size, int *numbers);
void	optimized_rotation(t_stack *a, t_stack *b);
int		ft_max(int a, int b);
void	min_operate(t_stack *a, t_stack *b, int a_idx, int b_idx, int *min);
void	get_min_rotate(t_stack *a, t_stack *b);
void	rotate_same(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);

#endif
