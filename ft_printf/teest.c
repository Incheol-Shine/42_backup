#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int j = 0;

	j = printf("%%%1\n");
	printf("%d\n",j);
	j = ft_printf("%%%1\n");
	printf("%d\n",j);
	
	// printf("\n");
	// printf("%%");
	// printf("\n");
	// printf("%%%d%%%", 1);
	// printf("\n");
	// printf("%%d%%", 1);
	// printf("\n");
	return (0);
}