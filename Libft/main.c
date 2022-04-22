#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <unistd.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	const char *str;

	char	*s1 = "A";

	char	*i1 = strnstr(s1, s1, 2);
	char	*i2 = ft_strnstr(s1, s1, 2);
	if (i1 == i2)
		printf("success\n");
	else
		printf("fail\n");
}
