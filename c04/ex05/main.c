#include <stdio.h>

int     ft_atoi_base(char *str, char *base);

int main(void)
{
    printf("answer: %d\n", ft_atoi_base(" --++2", "0123456789abcdef"));
    return (0);
}
