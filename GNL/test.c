#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	static char *backup = 0;

	printf("%lu\n", sizeof(backup));
	backup = (char *)malloc(10);
	printf("%lu\n", sizeof(backup));
}