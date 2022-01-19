#include <stdio.h>
#include <unistd.h>

void    *ft_print_memory(void *addr, unsigned int size);

void	put_address(unsigned long long addr, int length)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (length == 15)
	{
		c = base[addr];
		write(1, &c, 1);
	}
	else
	{
		put_address(addr / 16, length + 1);
		c = base[addr % 16];
		write(1, &c, 1);
	}
}

void	print_hex(unsigned char c)
{
	char	*base;

	base = "0123456789abcedf";
	write(1, base + (c / 16), 1);
	write(1, base + (c % 16), 1);
}

void	print_str(char *str)
{
	int i;

	while (i < 16 && str[i] != '\0')
	{
		if (32 <= str[i] && str[i] <= 126)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	print_spc(int i)
{
	while (i % 16 != 0)
	{
		if (i % 2 == 0)
			write(1, "  ", 2);
		else
			write(1, "   ", 3);
		i++;
	}
	return (i);
}

void    *ft_print_memory(void *addr, unsigned int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			put_address((unsigned long long)addr + i, 0);
			write(1, ": ", 2);
		}
		print_hex(*((unsigned char *)addr + i));
		if (i % 2 == 1)
			write(1, " ", 1);
		if (i % 16 == 15)
			print_str((char *)addr + (i - 15));
		i++;
	}
	i = print_spc(i);
	print_str((char *)addr + (i - 15));
}

int	main(void)
{
	char	str[] = "Bonjour les aminches...c est fo u.tout.ce qu on peut faire avec...print_memory.....lol.lol. .";
	int		size = sizeof(str) / sizeof(str[0]);

	ft_print_memory(str, size);
	return (0);
}
