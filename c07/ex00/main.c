#include <stdio.h>
#include <stdlib.h>
char    *ft_strdup(char *src);

int main(void)
{
	char *p;

	p = ft_strdup("Hello,");
	printf("%s\n", p);
	free(p);
	p = ft_strdup("HHHHHHAAAAIII");
	printf("%s\n", p);
	free(p);
	return (0);
}
