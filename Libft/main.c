#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*str_dup = strdup(str);

	if (!(str_dup = ft_strdup(str)))
		printf("null");
	else
		printf("str: %s", str_dup);
	return (0);
}