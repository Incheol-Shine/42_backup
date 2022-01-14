unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
    int i;

    i = 0;
    while (i < size && src[i] != '\0')
    {
        dest[size - 1 + i] = src[i];
        i++;
    }
    dest[size - 1 + i] = '\0';
    return (size + i);
}