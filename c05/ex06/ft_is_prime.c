#include <stdio.h>
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
int main(void)
{
    // int arr[] = {-2147483648,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,2147483029,
    // 2147483030,2147483031,2147483032,2147483033,2147483034,2147483035,
    // 2147483036,2147483037,2147483038,2147483039,2147483040,2147483041,
    // 2147483042,2147483043,2147483044,2147483045,2147483046,2147483047,
    // 2147483048,2147483049,2147483050,2147483051,2147483052,2147483053,
    // 2147483054,2147483055,2147483056,2147483057,2147483058,2147483059,
    // 2147483060,2147483068,2147483069,2147483070,2147483076,2147483077,
    // 2147483078,2147483122,2147483123,2147483124,2147483628,2147483629,
    // 2147483630,2147483646,2147483647};
    // int size = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i < 100; i++)
    {
        printf("%d is prime : (%d)\n", i, ft_is_prime(i));
        // printf("%d\n", ft_is_prime(arr[i]));
    }
    printf("%d\n", ft_is_prime(2147483029));
    return (0);
}