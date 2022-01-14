#include <stdio.h>

char    *ft_strcat(char *dest, char *src);

int main(void)
{
    char dest[] = "BAZA";
    char src[] = "aAZA";

    printf("%s", ft_strcat(dest, src));
    return (0);
}