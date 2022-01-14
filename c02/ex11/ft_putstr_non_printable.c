#include <unistd.h>
void    ft_putstr_non_printable(char *str);
void    str2hex(char c);
void    prthex(char c);

void    prthex(char c)
{
    char hex;

    if (c > 9)
        hex = c - 10 + 'a';
    else
        hex = c + '0';
    write(1, &hex, 1);
}

void    str2hex(char c)
{
    prthex(c / 16);
    prthex(c % 16);
}

void    ft_putstr_non_printable(char *str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        if (str[i] < 32 || 126 < str[i])
        {
            write(1, "\\", 1);
            str2hex(str[i]);
        }
        else
            write(1, str + i, 1);
        i++;
    }
}
int main(void)
{
    ft_putstr_non_printable("Coucou\ntu vas bien ?");
    return (0);
}