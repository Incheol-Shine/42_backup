char    *ft_strcat(char *dest, char *src);

char    *ft_strcat(char *dest, char *src)
{
    int i;
    int dest_len;

    i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    dest_len = i;
    while (src[i - dest_len] != '\0')
    {
        dest[i] = src[i - dest_len];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}