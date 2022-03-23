<<<<<<< HEAD
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	switch_chr(unsigned int i, char *c)
{
	printf("fn start - i: %d, c: %c\n", i, *c);
	if (*c >= 'a' && *c <= 'z')
	{
		printf("low\n");
		*c -= 32;
	}
	else if (*c >= 'A' && *c <= 'Z')
	{
		printf("HIGH\n");
		*c += 32;
	}
	printf("fn end - i: %d, c: %c\n", i, *c);
}

int main(void)
{
	char	*str = "hello world";

	ft_striteri(str, &switch_chr);
	printf("after: %s", str);
    return (0);
}
=======
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
>>>>>>> 52eecb1a988c4b8e2cde52fbe66aa31b7ae95a6f
