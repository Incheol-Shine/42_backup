#include <unistd.h>
void	ft_putnbr(int nb);
void	recursive(int nb, int plsMns);

void	recursive(int nb, int plsMns)
{
	char c;

	if (nb / 10 == 0)
	{
		c = (nb * plsMns) + '0';
		write(1, &c, 1);
	}
	else
	{
		recursive(nb / 10, plsMns);
		c = ((nb % 10) * plsMns) + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
		recursive(nb, 1);
	else
	{
		write(1, "-", 1);
		recursive(nb, -1);
	}
}

int main()
{
	ft_putnbr(2147483647);
	write(1,"\n",1);
	ft_putnbr(-2147483648);
	write(1,"\n",1);
	ft_putnbr(0);
}
