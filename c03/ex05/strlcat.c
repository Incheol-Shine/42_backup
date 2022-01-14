#include <string.h>
#include <stdio.h>

int main(void)
{
    char dest[] = "BAZA";
    char src[] = "aAZA";
    unsigned int size = sizeof(dest) / sizeof(dest[0]);

    printf("length : %d\n", strlcat(dest, src, size));
    printf("%s\n", dest);
    return (0);
}