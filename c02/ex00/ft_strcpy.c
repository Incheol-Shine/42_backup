#include <stdio.h>
char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

int	main(void)
{
	char src[] = "Hello! fella. Im good.";
	char cpy[] = "hahaha you shit";
	int size = sizeof(src) / sizeof(src[0]);

	printf("before: %s\n",cpy);
	ft_strcpy(cpy, src);
	printf("after: %s",cpy);
	return (0);
}
