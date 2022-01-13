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
		if (str[i] < 32 || 127 < str[i])
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
	char str[] = "     !!";
	
	printf("%d",ft_str_is_printable(str));
	return (0);
}
