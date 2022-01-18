#include <unistd.h>
#include <stdio.h>

int		ft_atoi_base(char *str, char *base);
int		is_right_input(char *base);
int		is_exist_same_char(char *base, int size);
int		base2int(char *str, char *base, int n);

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
	number = base2int(&str[i], base, base_number);
	return (plsmns * number);
}

int	base2int(char *str, char *base, int n)
{
	int	i;
	int	j;
	int	number;
	int	is_in_base;

	number = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		is_in_base = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				number = (number * n) + j;
				is_in_base = 1;
				break ;
			}
			j++;
		}
		if (!is_in_base)
			return (number);
		i++;
	}
	return (number);
}

int	main(void)
{
	printf("answer: %d\n", ft_atoi_base(" --++fffg42fg", "abcdefg"));
	return (0);
}
