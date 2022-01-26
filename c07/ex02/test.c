#include <stdio.h>
# define MAX 24
# define MIN 3

int ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*ptr[1];
	int i;

	printf("%d,\n", ft_ultimate_range(ptr, MIN, MAX));
	i = 0;
	while (i < (MAX - MIN))
	{
		printf("%d\n", *ptr[i]);
		i++;
	}
	return (0);
}
