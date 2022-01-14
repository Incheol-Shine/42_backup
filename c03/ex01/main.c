#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
    char str1[] = "asdf123";
    char str2[] = "asdf123";

    printf("%d", ft_strncmp(str1, str2, 0));
    return (0);
}