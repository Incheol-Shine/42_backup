/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:09:14 by incshin           #+#    #+#             */
/*   Updated: 2022/01/20 16:59:43 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	print_hex(unsigned char c, unsigned int j);
void	print_str(char *str);
void	put_address(unsigned long long addr, int length);
void	print_spc(unsigned int i);

void	put_address(unsigned long long addr, int length)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (length == 15)
	{
		c = base[addr];
		write(1, &c, 1);
	}
	else
	{
		put_address(addr / 16, length + 1);
		c = base[addr % 16];
		write(1, &c, 1);
		if (length == 0)
			write(1, ": ", 2);
	}
}

void	print_hex(unsigned char c, unsigned int j)
{
	char	*base;

	base = "0123456789abcedf";
	write(1, base + (c / 16), 1);
	write(1, base + (c % 16), 1);
	if (j % 2 == 1)
		write(1, " ", 1);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (32 <= str[i] && str[i] <= 126)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		if (str[i] == '\0')
			break ;
		i++;
	}
	write(1, "\n", 1);
}

void	print_spc(unsigned int j)
{
	if (j % 2 == 0)
		write(1, "  ", 2);
	else
		write(1, "   ", 3);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	if (!size)
		return (addr);
	i = 0;
	while (i <= (size - 1) / 16)
	{
		j = 0;
		put_address((unsigned long long)addr + (i * 16), 0);
		while (j < 16)
		{
			if ((i * 16) + j < size)
				print_hex(*((unsigned char *)addr + i * 16 + j), j);
			else
				print_spc(j);
			j++;
		}
		print_str((char *)addr + i * 16);
		i++;
	}
	return (addr);
}
