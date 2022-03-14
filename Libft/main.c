#include <stdio.h>
#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	main(void)
{
	const char s1[] = "";
	const char s2[] = "";

	printf("%d\n", ft_memcmp(s1, s2, 6));
	printf("%d\n", memcmp(s1, s2, 6));
	return (0);
}