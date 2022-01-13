#include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (src[i] != 0)
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = 0;
		}
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	main(void)
{
	char src[] = "Hello! fella.";
	char cpy[] = "hahaha you shit";
	int size = sizeof(src) / sizeof(src[0]);

	printf("before: %s\n",cpy);
	ft_strncpy(cpy, src, 8);
	printf("after: %s",cpy);
	return (0);
}
