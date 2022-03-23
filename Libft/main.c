#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	switch_chr(unsigned int i, char *c)
{
	printf("fn start - i: %d, c: %c\n", i, *c);
	if (*c >= 'a' && *c <= 'z')
	{
		printf("low\n");
		*c -= 32;
	}
	else if (*c >= 'A' && *c <= 'Z')
	{
		printf("HIGH\n");
		*c += 32;
	}
	printf("fn end - i: %d, c: %c\n", i, *c);
}

int main(void)
{
	char	*str = "hello world";

	ft_striteri(str, &switch_chr);
	printf("after: %s", str);
    return (0);
}