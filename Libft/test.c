#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *c = "hello";
	char **h;

	h = &c;
	// *j = c;
	printf("h : %p\n", h);	
	return (0);
}