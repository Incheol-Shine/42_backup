int ft_strncmp(char *s1, char *s2, unsigned int n);

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int i;

    i = 0;
    while (s1[i] == s2[i])
    {
        if (i == n - 1 || s1[i] == 0)
        {
            return (0);
        }
        i++;
    }
    if (s1[i] > s2[i])
    {
        return (1);
    }
    else
    {
        return (-1);
    }
}