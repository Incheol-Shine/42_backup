#include <stdio.h>

char    *ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
    char dest[] = "BAZA";
    char src[] = "aAZA";

    printf("%s", ft_strncat(dest, src, 0));
    return (0);
}