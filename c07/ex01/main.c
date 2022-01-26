#include <stdlib.h>
#include <stdio.h>

# define MIN -2147483648
# define MAX 2147483647

int *ft_range(int min, int max);

int main()
{
	int *ptr;

	ptr = ft_range(MIN, MAX);
	printf("Done!\n");
	printf("min:%d, max:%d\n", ptr[0],ptr[MAX-MIN-1]);
//	for (unsigned int i=0; i < (MAX - MIN); i++)
//	{
//		printf("%d\n", ptr[i]);
//	}
	free(ptr);

	return (0);
}
