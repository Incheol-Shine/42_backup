char    *ft_convert_base(char *nbr, char *base_from, char *base_to);
int     idx_base(char c, char *base);
int     ft_strlen(char *str);
char    *trim_nbr(int nbr, char *base);

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int i;
    int sign;
    int base;

    i = trim_nbr(nbr, base_from);
    sign = 1
    if (i < 0)
    {
        i *= -1
        sign = -1;
    }
    base_nbr = ft_strlen(base_from);
    while (nbr[i])
    {
        idx = idx_base(nbr[i], base_from)
        if (idx < 0)
            return (0);
        n = n * base_nbr + base_from[idx];
    }
    return (n * sign);
}

int trim_nbr(char *nbr, char *base)
{
    int sign;
    int i;

    i = 0;
    while (nbr[i] == ' ' || (9 <= nbr[i] && nbr[i] <= 13))
        i++;
    sign = 1;
    while (nbr[i] == '+' || nbr[i] == '-')
    {
        if (nbr[i] == '-')
            sign *= -1;
        i++;
    }
    return (i * sign)
}

{
    base_nbr = ft_strlen(base_from);
    while (nbr[i])
    {
        idx = idx_base(nbr[i], base_from)
        if (idx < 0)
            return (0);
        n = n * base_nbr + base_from[idx];
    }
    return (n * sign);
}

char    *ft_itoa(int nbr, char *base)
{
    char *ptr;

    ptr =
    return (ptr);
}

int idx_base(char c, char *base)
{
    int i;

    i = 0;
    while (base[i] != '\0')
    {
        if (c == base[i])
            return (i);
        i++;
    }
    return (-1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
