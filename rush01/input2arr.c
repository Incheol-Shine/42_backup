#include <stdio.h>

int	is_right_input(char *str);
int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_right_input(char *str)
{
	int	str_len;
	int	n;
	int	i;

	str_len = ft_strlen(str);
	if ((str_len + 1) % 8 != 0)
		return (0);
	n = (str_len + 1) / 8;
	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || n + '0' < str[i])
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (n);
}
