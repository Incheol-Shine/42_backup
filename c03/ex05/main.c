#include <stdio.h>

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
    char dest[] = "BAZA";
    char src[] = "aAZA";
    unsigned int size = sizeof(dest) / sizeof(dest[0]);

    printf("length : %d\n", ft_strlcat(dest, src, size));
    printf("%s\n", dest);
    return (0);
}