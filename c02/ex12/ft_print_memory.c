#include <stdio.h>
#include <unistd.h>

void    *ft_print_memory(void *addr, unsigned int size);

void    *ft_print_memory(void *addr, unsigned int size)
{
	if (size == 0)
		return ;
	printf("%p", addr);
}

int	main(void)
{
	char	str[] = "Bonjour les aminches...c est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. .";
	int		size = sizeof(str) / sizeof(str[0]);

	ft_print_memory(str, size);
	return (0);
}
