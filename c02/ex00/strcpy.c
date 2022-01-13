#include <string.h>
#include <stdio.h>

int main(void)
{
	char src[] = "AnacondaIsVeryBigSnake";
	char dest[] = "LaBicicletaMiCasaMuchasGrasias";
	int size_dst = sizeof(dest) / sizeof(dest[0]);
	int size_src = sizeof(src) / sizeof(src[0]);

	printf("%d,  %d\n",size_dst, size_src);
	printf("before : %s\n", dest);
	printf("call strcpy : %s\n", strcpy(dest, src));
	dest[size_src - 1] = 'z';
	printf("after : %s\n", dest);
	return (0);
}
