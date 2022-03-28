#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *c = "hello";
	char *d = "Hi";
	char **h;

	h = &c;
	// h = (char **)malloc(sizeof(char *));
	// if(!h)
	// 	return (0);
	// *h = c;
	printf("c: %p\n", c);
	printf("c_val: %s\n", c);
	printf("h_val_val: %s\n", *h);
	*h = d;
	printf("c: %p\n", c);
	printf("c_val: %s\n", c);
	printf("h_val_val: %s\n", *h);
	printf("d: %p\n", d);
	printf("d_val: %s\n", d);

	// free(h);
	return (0);
}