char	**ft_split(char *str, char *charset);
int		is_in_charset(char c);
int		ft_strlen(char *str);

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		size;
	char	**dest;

	size = ft_destlen(str, charset);
	dest = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	j = 0;
	while (i < size)
	{
		
	}
}

int		ft_destlen(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i + 1])
	{
		if (!(is_in_charset(str[i], charset)))
		{
			if(is_in_charset(str[i + 1], charset))
				size ++;
		}
		else if (i == 0)
			size ++;
		i++;
	}
	return (size);
}

int	is_in_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
