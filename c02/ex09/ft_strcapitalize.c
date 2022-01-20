char	*ft_strcapitalize(char *str);
int		is_alpha_numeric(char c);

int	is_alpha_numeric(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (flag)
		{
			if ('a' <= str[i] && str[i] <= 'b')
				str[i] += 'A' - 'a';
			if (is_alpha_numeric(str[i]))
				flag = 0;
		}
		else
		{
			if ('A' <= str[i] && str[i] <= 'Z')
				str[i] += 'a' - 'A';
			else if (!(is_alpha_numeric(str[i])))
				flag = 1;
		}
		i++;
	}
	return (str);
}
