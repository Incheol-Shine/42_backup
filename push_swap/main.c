/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:39 by incshin           #+#    #+#             */
/*   Updated: 2022/11/19 12:08:08 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_pivot	pivot;
	int		*numbers;

	if (argc < 2)
		print_error_exit(ARG_ERR);
	numbers = str_to_int_arr(argc - 1, argv);
	check_overlap_pivot(argc - 1, numbers, &pivot);
	check_already_sort(argc - 1, numbers);
	a = fill_stack(argc - 1, numbers);
	b = init_stack();
	wheel_sort(a, b, pivot);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
