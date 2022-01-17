int	ft_atoi(char *str);
int ft_char_is_numeric(char c);

int	ft_char_is_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int plsMns;
	int i;
	int number;

	i = 0;
	while(str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	plsMns = 1;
	while(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			plsMns *= -1;
		i++;
	}
	number = 0;
	while(ft_char_is_numeric(str[i]) && str[i] != '\0')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (plsMns * number);
}
