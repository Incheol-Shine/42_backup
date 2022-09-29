/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:20:54 by incshin           #+#    #+#             */
/*   Updated: 2022/09/29 16:50:50 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("sig : 0");
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("sig : 1");
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	return (0);
}