#include <string.h>
#include <stdio.h>
//unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char src[] = "abcdefadsfs";
	char cpy[] = "12345678901234567";
	int size = sizeof(cpy) / sizeof(cpy[0]);
	int ans = 0;

	printf("before: %s\n",cpy);
	ans = strlcpy(cpy, src, size);
	printf("after: %s\n",cpy);
	printf("length: %d",ans);
	return (0);
}