#include <stdio.h>
int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int i;
	int is_lower;

	i = 0;
	is_lower = 1;
	while (str[i] != 0)
	{
		if (str[i] < 'a' || 'z' < str[i])
		{
			is_lower = 0;
			break ;
		}
		i++;
	}
	return (is_lower);
}

int	main(void)
{
	char str[] = "itislowercasestring";

	printf("%d",ft_str_is_lowercase(str));
	return (0);
}
