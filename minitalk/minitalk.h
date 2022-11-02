/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:22:03 by incshin           #+#    #+#             */
/*   Updated: 2022/10/07 13:23:01 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

void	fin_a_letter(int sig);
void	send_letter(pid_t pid, char letter);
void	send(pid_t pid, char *str);
void	handler(int sig, siginfo_t *info, void *other);

#endif