#include <stdio.h>
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != 0)
	{
		if (i == size - 1)
			dest[i] = 0;
		else if (i < size - 1)
			dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (i + 1);
}

int	main(void)
{
	char src[] = "abcdefadsfs";
	char cpy[] = "12345678901234567";
	int size = sizeof(cpy) / sizeof(cpy[0]);
	int ans = 0;

	printf("before: %s\n",cpy);
	ans = ft_strlcpy(cpy, src, size);
	printf("after: %s\n",cpy);
	printf("length: %d",ans);
	return (0);
}
