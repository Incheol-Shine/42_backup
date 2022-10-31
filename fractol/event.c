/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:06:29 by incshin           #+#    #+#             */
/*   Updated: 2022/10/30 18:34:55 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define KEY_ESC		53

int	close(int keycode, t_win *vars)
{
	printf("%d\n", keycode);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

