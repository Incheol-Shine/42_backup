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
			if (*(temp + 1) == 'c')
				return_size += func_c(ap);
			else if (*(temp + 1) == 's')
				return_size += func_s(ap);
			else if (*(temp + 1) == 'p')
				return_size += func_p(ap);
			else if (*(temp + 1) == 'd' || *(temp + 1) == 'i')
				return_size += func_di(ap);
			else if (*(temp + 1) == 'u')
				return_size += func_u(ap);
			else if (*(temp + 1) == 'x')
				return_size += func_x(ap, 0);
			else if (*(temp + 1) == 'X')
				return_size += func_x(ap, 1);
			else if (*(temp + 1) == '%')
				return_size += func_percent();
			else
			{
				temp++;
				continue;
			}
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



