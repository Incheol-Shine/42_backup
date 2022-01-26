char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		idx_base(char c, char *base);
int		ft_strlen(char *str);
char	*ft_itoa(int nbr, char *base);
int		is_right_base(char *base);
int		is_exist_same_char(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int n;
	int sign;
	int base_nbr;
	int i;
	int idx;

	i = 0;
	while (nbr[i] == ' ' || (9 <= nbr[i] && nbr[i] <= 13))
		i++;
	sign = 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	base_nbr = ft_strlen(base_from);
	while (nbr[i])
	{
		idx = idx_base(nbr[i], base_from)
		if (idx < 0)
			return (0);
		n = n * base_nbr + idx;
	}
	
}

int	is_right_base(char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] = '+' || base[i] = ' ')
			return (0);
		i++;
	}
	return (1);
}



int	idx_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
