#include <stdio.h>
int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int i;
	int is_alpha;

	i = 0;
	is_alpha = 1;
	while (str[i] != 0)
	{
		if (str[i] < 'A' || 'z' < str[i] || ('Z' < str[i] && str[i] < 'a'))
		{
			is_alpha = 0;
			break ;
		}
		i++;
	}
	return (is_alpha);
}

int	main(void)
{
	char str[] = "spacei notalphabetok";

	printf("%d",ft_str_is_alpha(str));
	return (0);
}
