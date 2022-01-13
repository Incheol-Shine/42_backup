#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	n;
	char src[] = "ImaBirdAndYouraWorm";
	//char dst[] = "DespacitoMuchogustoGracias";
	char dst2[30] = "1234567891234567890012";
	int size = sizeof(src) / sizeof(src[0]);

	n = 25;
	printf("before : %s\n", dst2);
	printf("Call strncpy : %s\n", strncpy(dst2, src, n));
	dst2[size-1] = 'z';
	dst2[size] = 'z';
	printf("after : %s\n", dst2);
}
