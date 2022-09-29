#ifndef FT_PRINTF_H

# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_format(va_list ap, char format);
int		func_c(va_list ap);
int		func_s(va_list ap);
int		func_p(va_list ap);
void	print_hex(int *cnt, unsigned long addr, int isupper);
int		func_di(va_list ap);
int		func_u(va_list ap);
void	print_dec(int *cnt, unsigned int num);
int		func_x(va_list ap, int isupper);
int		func_percent();
#endif