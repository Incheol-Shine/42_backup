#include <stdio.h>
int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int i;
	int is_upper;

	i = 0;
	is_upper = 1;
	while (str[i] != 0)
	{
		if (str[i] < 'A' || 'Z' < str[i])
		{
			is_upper = 0;
			break ;
		}
		i++;
	}
	return (is_upper);
}

int	main(void)
{
	char str[] = "ITISnotUPPERCASESTRING";

	printf("%d",ft_str_is_uppercase(str));
	return (0);
}
