/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:22:06 by incshin           #+#    #+#             */
/*   Updated: 2022/10/07 00:32:53 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_handler_flag;

void	param_error(void)
{
	ft_printf("usage: ./client [server-pid] [message]\n");
	exit(0);
}

void	sig_feedback(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Signal Received.\n");
	g_handler_flag = 1;
}

void	send_letter(pid_t pid, char letter)
{
	unsigned char	temp;

	temp = 1 << 7;
	while (temp)
	{
		if (letter & temp)
		{
			if (kill(pid, SIGUSR2))
				exit(0);
			while (!g_handler_flag)
				continue ;
		}
		else
		{
			if (kill(pid, SIGUSR1))
				exit(0);
			while (!g_handler_flag)
				continue ;
		}
		g_handler_flag = 0;
		temp >>= 1;
		usleep(40);
	}
}

void	send(pid_t pid, char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	while (str_len--)
		send_letter(pid, *(str++));
	send_letter(pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	g_handler_flag = 0;
	if (argc != 3)
		param_error();
	server_pid = (pid_t)ft_atoi(argv[1]);
	signal(SIGUSR1, sig_feedback);
	signal(SIGUSR2, sig_feedback);
	send(server_pid, argv[2]);
	return (0);
}
