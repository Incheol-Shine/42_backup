#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	switch_chr(unsigned int i, char *c)
{
	i += i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

int main(void)
{
	char	str[12] = "LoReM iPsUm";

	ft_striteri(str, &switch_chr);
	printf("after: %s", str);
    return (0);
}
