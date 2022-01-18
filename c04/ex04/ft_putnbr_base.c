#include <unistd.h>
#include <stdio.h>
void	ft_putnbr_base(int nbr, char *base);
int		is_right_input(char *base);
int		is_exist_same_char(char *base, int size);
void	recursive(int nbr, int plsmns, int n, char *base);

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
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	if (is_exist_same_char(base, i))
		return (0);
	return (i);
}

void	recursive(int nbr, int plsmns, int n, char *base)
{
	char	c;

	if (nbr / n == 0)
	{
		c = base[nbr * plsmns];
		write(1, &c, 1);
	}
	else
	{
		recursive(nbr / n, plsmns, n, base);
		c = base[plsmns * (nbr / n)];
		write(1, &c, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = is_right_input(base);
	write(1, &n, 1);
	if (!n)
		return ;
	if (nbr >= 0)
		recursive(nbr, 1, n, base);
	else
	{
		write(1, "-", 1);
		recursive(nbr, -1, n, base);
	}
}

int	main(void)
{
	ft_putnbr_base(42, "asdfg");
	return (0);
}
