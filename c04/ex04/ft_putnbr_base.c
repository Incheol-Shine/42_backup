void	ft_putnbr_base(int nbr, char *base);
int		is_right_input(char *base);
int		is_exist_same_char(char *base, int size);

int	is_exist_same_char(char *base, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
}

int	is_right_input(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	if (is_exist_same_char(base, i))
		return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (is_right_input(base))
		return ();
	
}
