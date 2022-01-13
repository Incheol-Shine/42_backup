#include <stdio.h>
int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int i;
	int is_num;

	i = 0;
	is_num = 1;
	while (str[i] != 0)
	{
		if (str[i] < '0' || '9' < str[i])
		{
			is_num = 0;
			break ;
		}
		i++;
	}
	return (is_num);
}

int	main(void)
{
	char str[] = "123413253154709876533211";

	printf("%d",ft_str_is_numeric(str));
	return (0);
}
