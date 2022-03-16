#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);
int 	main() 
{ 
	char const	str[] = "012345678901234";
	char		*sub_str;

	sub_str = ft_substr(str, 3, 6);
	// for(int i = 0; i < 6; i++)
	// 	printf("%c", sub_str[i]);
	printf("%s", sub_str);
	printf("\n");
	free(sub_str);
}
