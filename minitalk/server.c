/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:20:54 by incshin           #+#    #+#             */
/*   Updated: 2022/10/07 12:35:05 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *other)
{
	static char	letter = 0;
	static int	cnt = 0;

	(void)other;
	if (sig == SIGUSR1)
	{
		letter <<= 1;
		kill(info -> si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		letter <<= 1;
		letter += 1;
		kill(info -> si_pid, SIGUSR1);
	}
	if (cnt == 7)
	{
		write(1, &letter, 1);
		if (!letter)
			kill(info -> si_pid, SIGUSR2);
		cnt = 0;
		letter = 0;
	}
	else
		cnt++;
}

int	main(void)
{
	struct sigaction	sig_strct;

	ft_printf("PID : %d\n", getpid());
	sig_strct.sa_sigaction = handler;
	sig_strct.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_strct, NULL);
	sigaction(SIGUSR2, &sig_strct, NULL);
	while (1)
		continue ;
	return (0);
}
