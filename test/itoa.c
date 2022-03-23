#include <stdio.h>
#include <stdlib.h>

char    *ft_itoa_base(int nbr, char *base);
int     ft_nbr_len(int nbr, int base_len);
void    recursive_minus(int nbr, int base_n, char *ptr);
void    recursive_plus(int nbr, int base_n, char *ptr);

int     ft_nbr_len(int nbr, int base_len)
{
    int i;

    i = 0;
    while (nbr)
    {
        nbr /= base_len;
        i++;
    }
    return (i);
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_itoa_base(int nbr, char *base)
{
    char *result_nbr;
    int base_len;
    int nbr_len;

    base_len = ft_strlen(base);
    nbr_len = ft_nbr_len(nbr, base_len);

    if (nbr >= 0)
    {
        result_nbr = (char *)malloc(sizeof(char) * (nbr_len + 1));
        if (!result_nbr)
            return (0);
        recursive_plus(nbr, base_len, result_nbr);
    }
    else
    {
        result_nbr = (char *)malloc(sizeof(char) * (nbr_len + 1));
        if (!result_nbr)
            return (0);
        result_nbr[0] = '-'
        recursive_minus(nbr, base_len, result_nbr + 1);
    }
}

recursive_minus(int nbr, int base_n, char *ptr)
{
    if (nbr / base_n)
    {
        
    }
}









int main()
{
    printf("%s", ft_itoa_base(16, "0123456789abcdef"));
    return (0);
}