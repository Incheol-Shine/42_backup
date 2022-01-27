#include <stdio.h>

char    *ft_convert_base(char *nbr, char *base_from, char *base_to);
char    *ft_itoa(int nbr, char *base);
int     ft_atoi_base(char *nbr, char *base_from);

int main(void)
{
	char	nbr[] = "a";
	char	b1[] = "0123456789abcdef";
	char	b2[] = "0123456789";

    printf("convert_base: %s\n", ft_convert_base(nbr, b1, b2));
	printf("str_to_int: %d\n", ft_atoi_base("-22", b1));
	printf("int_to_str: %s\n", ft_itoa(-12, b2));
    return (0);
}
