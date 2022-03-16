#include <stdio.h>
char    *ft_strstr(char *str, char *to_find);
int     ft_strlen(char *str);

int     ft_strlen(char *str)
{
    int len;

    len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return (len);
}

char    *ft_strstr(char *str, char *to_find)
{
    int     str_len;
    int     find_len;
    int     i;
    int     j;
    
    str_len = ft_strlen(str);
    find_len = ft_strlen(to_find);
    i = 0;
    j = 0;
    while (0 <= i && i <= str_len - find_len)
    {
        while (str[i] == to_find[j])
        {
            i++;
            j++;
            if (to_find[j] == '\0')
                return (&str[i - j]);
        }
        i = i - j + 1;
        j = 0;
    }
    return ('\0');
}
