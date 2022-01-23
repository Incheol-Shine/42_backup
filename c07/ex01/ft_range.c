#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
		return (NULL);
	ptr = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min + i < max)
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}
