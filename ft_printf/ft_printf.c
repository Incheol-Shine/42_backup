#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		return_size;
	va_list	ap;
	char	*temp;

	return_size = 0;
	va_start(ap, format);
	temp = (char *)format;
	while (*temp)
	{
		if (*temp == '%')
		{
			return_size += ft_format(ap, *(temp + 1));
			temp++;
		}
		else
		{
			write(1, temp, 1);
			return_size++;
		}
		temp++;
	}
	va_end(ap);
	return (return_size);
}

int	ft_format(va_list ap, char format)
{
	int	return_size = 0;
	
	if (format == 'c')
		return_size = func_c(ap);
	else if (format == 's')
		return_size = func_s(ap);
	else if (format == 'p')
		return_size = func_p(ap);
	else if (format == 'd' || format == 'i')
		return_size = func_di(ap);
	else if (format == 'u')
		return_size = func_u(ap);
	else if (format == 'x')
		return_size = func_x(ap, 0);
	else if (format == 'X')
		return_size = func_x(ap, 1);
	else if (format == '%')
		return_size = func_percent();
	return (return_size);
}



