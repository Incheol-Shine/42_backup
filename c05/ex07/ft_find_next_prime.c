#include <stdio.h>
int ft_find_next_prime(int nb);
int ft_is_prime(int nb);
int ft_sqrt(unsigned int nb, unsigned int x);
int ft_prime_sub(int nb, int sqrt);

int ft_sqrt(unsigned int nb, unsigned int x)
{
    if (x * x >= nb)
        return ((int)x);
    else
        return (ft_sqrt(nb, x + 1));
}

int ft_prime_sub(int nb, int sqrt)
{
    if (sqrt <= 1)
        return (1);
    else if (nb == 2)
        return (1);
    else if (nb % sqrt == 0)
        return (0);
    else
        return (ft_prime_sub(nb, sqrt - 1));
}

int ft_is_prime(int nb)
{
    int sqrt;

    if (nb <= 1)
        return (0);
    sqrt = ft_sqrt((unsigned int)nb, 1);
    return (ft_prime_sub(nb, sqrt));
}

int ft_find_next_prime(int nb)
{
    if (ft_is_prime(nb))
        return (nb);
    else
        return (ft_find_next_prime(nb + 1));
}

int main(void)
{
    printf("%d\n", ft_find_next_prime(1877392079));// 최대 
    return (0);
}