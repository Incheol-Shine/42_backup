#include <unistd.h>

int		ft_atoi_base(char *str, char *base);
int		is_right_input(char *base);
int		is_exist_same_char(char *base, int size);
int		idx_base(char c, char *base);

int	is_exist_same_char(char *base, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
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
	return (0);
}

int	is_right_input(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	if (is_exist_same_char(base, i))
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	plsmns;
	int	i;
	int	number;
	int	base_number;
	int idx;

	base_number = is_right_input(base);
	if (!base_number)
		return (0);
	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	plsmns = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			plsmns *= -1;
		i++;
	}
	number = 0;
	while (str[i])
	{
		idx = idx_base(str[i], base);
		if (idx < 0)
			return (plsmns * number);
		number = (number * base_number) + idx;
		i++;
	}
	return (plsmns * number);
}

int	idx_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}
