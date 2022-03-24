#include <stdio.h>
#include <stdlib.h>

char    **ft_split(char *str, char *charset);

int main(int argc, char **argv)
{
    char *charset = "012345";
    char **dest;

    int i;

    dest = ft_split(argv[1], charset);
    i = 0;
    argc = 1;
    while (dest[i] != NULL)
    {
        printf("%s\n", dest[i]);
        free(dest[i]);
        i++;
    }
    free(dest);
    return (0);
}
