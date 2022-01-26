#include <stdio.h>

char    *ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	printf("size : %d\n", argc - 1);
	printf("%s\n",ft_strjoin(argc - 1, argv + 1, "~~!~~"));
	return (0);
}
