#include <stdio.h>

int ft_fibonacci(int index);

int main(void)
{
    for (int i=0; i < 10; i++)
    {
        printf("%d ",ft_fibonacci(i));
    }
    printf("\n");
    printf("%d",ft_fibonacci(-2));
    return (0);

}