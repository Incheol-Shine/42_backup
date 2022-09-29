/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:22:06 by incshin           #+#    #+#             */
/*   Updated: 2022/09/29 16:48:31 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*string = argv[2];

	server_pid = ft_atoi(argv[1]);
	ft_printf("pid : %d\n", server_pid);
	ft_printf("string : %s\n", string);

	return (0);
}
