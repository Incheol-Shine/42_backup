#include <stdio.h>
void	*ft_print_memory(void *addr, unsigned int size);

int main(void)
{
    //char str[] = "hello \nworld all people \nim very \nvery good!@#$!#^$:&";
    char str[1];

    str[0] = 34;
    unsigned int size = sizeof(str) / sizeof(str[0]);

    ft_print_memory(str, 1);
    return (0);
}