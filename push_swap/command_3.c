/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:19:00 by incshin           #+#    #+#             */
/*   Updated: 2022/11/18 20:58:20 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b)
{
	revolve(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	revolve(a);
	revolve(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	reverse_revolve(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_revolve(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_revolve(a);
	reverse_revolve(b);
	write(1, "rrr\n", 4);
}
