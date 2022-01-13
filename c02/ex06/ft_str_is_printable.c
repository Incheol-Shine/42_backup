#include <stdio.h>
int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int i;
	int is_printable;

	i = 0;
	is_printable = 1;
	while (str[i] != 0)
	{
		if (str[i] < 32 || 126 < str[i])
		{
			is_printable = 0;
			break ;
		}
		i++;
	}
	return (is_printable);
}

int	main(void)
{
	char str[] = "aaaaaaaa";

	str[2] = 32;
	printf("%d",ft_str_is_printable(str));
	printf("%s",str);
	return (0);
}
