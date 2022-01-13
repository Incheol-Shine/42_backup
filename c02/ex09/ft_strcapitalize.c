#include <stdio.h>
char	*ft_strcapitalize(char *str);
int		ft_str_is_word(char *str, int i);

int		ft_str_is_word(char *str, int i)
{
	while (str[i] != 0)
	{
		if (str[i] < '0' || ('9' < str[i] && str[i] < 'A'))
		{
			break ;
		}
		if (('Z' < str[i] && str[i] < 'a') || 'z' < str[i])
		{
			break ;
		}
		i++;
	}
	return i;
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i = ft_str_is_word(str, i);
		i++;
	}
	return (str);
}
int	main(void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s", ft_strcapitalize(str));
}
