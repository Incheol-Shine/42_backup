#include "ft.h"
#include <stdio.h>
int main(void)
{
	int a;
	int b = 1;

	ft_putchar('a');
	printf("\n");
	ft_putstr("asdf");
	printf("\n");
	printf("%d\n",ft_strcmp("asdaf", "qwer"));
	a = ft_strlen("hello");
	printf("%d\n",a);
	ft_swap(&a, &b);
	printf("%d, %d\n", a, b);
	return (0);
}
