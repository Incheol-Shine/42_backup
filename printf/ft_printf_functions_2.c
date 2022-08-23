#include "ft_printf.h"

int	func_u(va_list ap)
{
	unsigned int	u;
	int				len;

	len = 0;
	u = va_arg(ap, int);
	if (!u)
	{
		write(1, "0", 1);
		return (1);
	}
	print_dec(&len, u);
	return (len);
}

void	print_dec(int *cnt, unsigned int num)
{
	char	*base;
	
	base = "0123456789";
	if (num)
	{
		print_dec(cnt, num / 10);
		write(1, base + (num % 10), 1);
		(*cnt)++;
	}
}

int	func_x(va_list ap, int isupper)
{
	unsigned int	u;
	int				len;

	len = 0;
	u = va_arg(ap, int);
	if (!u)
	{
		write(1, "0", 1);
		return (1);
	}
	print_hex(&len, u, isupper);
	return (len);
}

int	func_percent()
{
	write(1, "%", 1);
	return (1);
}