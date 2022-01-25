#include "rush02.h"

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	unsigned int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2 || argc > 3)
		return (0);
	if (argv[1][0] == '\0')
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (0);
		i++;
	}
	return (i);
}

int	gest_argv(int argc, char **argv, char **nb, char **dictpath)
{
	if (argc == 2)
	{
		*dictpath = "numbers.dict";
		*nb = argv[1];
		return (1);
	}
	else if (argc == 3)
	{
		*dictpath = argv[1];
		*nb = argv[2];
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*nb;
	char	*dictpath;
	int		len;
	int		tmp;

	len = check_arg(argc, argv);
	if (!len)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	tmp = gets_argv(argc, argv, &nb, &dictpath);
	if (!tmp)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_parse_dict(&nb, &dictpath);
	return (0);
}
