/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:39 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 22:40:52 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

// int main(void)
int	main(int argc, char *argv[])
{
	t_stack	*aa;
	t_stack	*bb;
	t_pivot	pivot;
	int		*numbers;
	// int argc = 11;
	// char *argv[11] = {"push_swap","9","8","7","6","5","4","3","2","1","0"};

	if (argc < 2)
		print_error_exit(ARG_ERR);
	
	numbers = str_to_int_arr(argc - 1, argv);
	check_already_sort(argc - 1, numbers);
	check_overlap_pivot(argc - 1, numbers, &pivot);
	aa = fill_stack(argc - 1, numbers);
	bb = init_stack();
	// ft_printf("%d, %d, %d\n", pivot.one_third, pivot.two_third);
	wheel_sort(aa, bb, pivot);
	// show_stack(aa);
	// show_stack(bb);
	clear_stack(aa);
	clear_stack(bb);
	return (0);
}
