char    *ft_strncat(char *dest, char *src, unsigned int nb);

char    *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int i;
    int dest_len;

    i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    dest_len = i;
    while (i - dest_len < nb && src[i - dest_len] != '\0')
    {
        dest[i] = src[i - dest_len];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}