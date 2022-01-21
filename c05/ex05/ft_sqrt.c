#include <stdio.h>
int ft_sqrt(int nb);
int recursive(unsigned nb, unsigned x);

int recursive(unsigned nb, unsigned x)
{
    if (x * x == nb)
        return (x);
    else if (x * x > nb)
        return (0);
    else
        return (recursive(nb, x + 1));
}

int ft_sqrt(int nb)
{
    return (recursive((unsigned int)nb, 1));
}

int main(void)
{
    printf("%d", ft_sqrt(1878182244)); //최대값
}