/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:39 by incshin           #+#    #+#             */
/*   Updated: 2022/11/16 19:12:17 by incshin          ###   ########.fr       */
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
	// ft_printf("%d, %d, %d ", pivot.one_third, pivot.a_half, pivot.two_third);
	wheel_sort(aa, bb, pivot);
	// show_stack(aa);
	return (0);
}

	// show_stack(aa);
	// show_stack(bb);
	// printf("top: %p\n", aa->top);
	// printf("bottom: %p\n", aa->bottom);
	// swap(aa);
	// show_stack(aa);
	// printf("top: %p\n", aa->top);
	// printf("bottom: %p\n", aa->bottom);
	// rotate(aa);
	// rotate(aa);
	// show_stack(aa);
	// printf("top: %p\n", aa->top);
	// printf("bottom: %p\n", aa->bottom);
	// reverse_rotate(aa);
	// reverse_rotate(aa);
	// reverse_rotate(aa);
	// show_stack(aa);
	// printf("top: %p\n", aa->top);
	// printf("bottom: %p\n", aa->bottom);

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
	// printf("top: %p\n", aa->top);
	// printf("bottom: %p\n", aa->bottom);
	// show_stack(aa);
	// clear_stack(bb);
	// show_stack(bb);