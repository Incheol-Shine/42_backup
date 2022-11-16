/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:33:21 by incshin           #+#    #+#             */
/*   Updated: 2022/11/16 19:14:50 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_exit(int err_no)
{
	if (err_no == ARG_ERR)
		// ft_printf("main : arg error\n");
		exit(0);
	else if (err_no == MALLOC_ERR)
		// ft_printf("init_stack / new_node : malloc error\n");
		exit(0);
	else if (err_no == ATOI_ERR)
		// ft_printf("atoi : not int type\n");
		exit(0);
	else if (err_no == ALREADY_SORTED)
		// ft_printf("already sorted\n");
		exit(0);
	exit(0);
}