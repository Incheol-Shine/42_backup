#include <stdio.h>

int ft_strcmp(char *s1, char *s2);

int main(void)
{
    char str1[] = "BAZA";
    char str2[] = "aAZA";

    printf("%d", ft_strcmp(str1, str2));
    return (0);
}