#include <stdio.h>
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	
	i = 0;
	while (src[i] != 0)
	{
		while (i < size - 1)
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
		i++;
	}

	i = 0;
	while (src[i])

	return (i);
}

int	main(void)
{
	char src[] = "abcdefghijklmno";
	char cpy[] = "12345678901234567";
	int ans = 0;

	printf("before: %s\n",cpy);
	ans = ft_strlcpy(cpy, src, 18);
	printf("after: %s\n",cpy);
	printf("length: %d",ans);
	return (0);
}
