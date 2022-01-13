#include <stdio.h>
char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "It changes every Letter5 to Uppercase ~ !";

	printf("%s", ft_strupcase(str));
	return (0);
}
