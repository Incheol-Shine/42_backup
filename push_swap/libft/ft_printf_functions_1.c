/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:05:29 by incshin           #+#    #+#             */
/*   Updated: 2022/09/29 14:47:19 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	func_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	func_s(va_list ap)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = (int)ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	func_p(va_list ap)
{
	void	*addr;
	int		len;

	addr = va_arg(ap, void *);
	len = 2;
	write(1, "0x", 2);
	if (!addr)
	{
		write(1, "0", 1);
		len++;
	}
	else
		print_hex(&len, (unsigned long)addr, 0);
	return (len);
}

void	print_hex(int *cnt, unsigned long addr, int isupper)
{
	char	*base;

	base = "0123456789abcdef";
	if (isupper)
		base = "0123456789ABCDEF";
	if (addr)
	{
		print_hex(cnt, addr / 16, isupper);
		write(1, base + (addr % 16), 1);
		(*cnt)++;
	}
}

int	func_di(va_list ap)
{
	char	*str;
	int		n;
	int		len;

	n = va_arg(ap, int);
	str = ft_itoa(n);
	len = (int)ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
