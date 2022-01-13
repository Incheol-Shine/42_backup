#include <stdio.h>
char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "It Changes Every Letter5 To lOWERCASE ~ !";

	printf("%s", ft_strlowcase(str));
	return (0);
}
