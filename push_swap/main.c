/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:39 by incshin           #+#    #+#             */
/*   Updated: 2022/11/17 13:38:31 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	"push_swap.h"

int	main(int argc, char *argv[])
{

	t_stack	*aa;
	t_stack *bb;
	t_pivot	pivot;
	int		*numbers;

	if (argc < 2)
		print_error_exit(ARG_ERR);
	numbers = str_to_int_arr(argc - 1, argv);
	check_overlap_pivot(argc - 1, numbers, &pivot);
	aa = fill_stack(argc - 1, numbers);
	bb = init_stack();
	// ft_printf("%d, %d, %d\n", pivot.one_third, pivot.a_half, pivot.two_third);
	wheel_sort(aa, bb, pivot);
	// show_stack(aa);
	// show_stack(bb);
	return (0);
}

// int	main(int argc, char *argv[])
// {

// 	t_stack	*aa;
// 	t_stack *bb;
// 	t_pivot	pivot;
// 	int		*numbers;

// 	if (argc < 2)
// 		print_error_exit(ARG_ERR);
// 	numbers = str_to_int_arr(argc - 1, argv);
// 	check_overlap_pivot(argc - 1, numbers, &pivot);
// 	aa = fill_stack(argc - 1, numbers);
// 	bb = init_stack();
// 	stack_add(bb, new_node(3));
// 	many_elem_sort(aa,bb,pivot);
// 	show_stack(aa);
// 	show_stack(bb);
// 	return (0);
// }