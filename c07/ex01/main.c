#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max);

int main()
{
	int *ptr;

	ptr = ft_range(5, 6);
	for (int i=0; i < 1; i++)
	{
		printf("%d ", ptr[i]);
	}
	free(ptr);

	printf("%p", ft_range(3, 3));
	return (0);
}
