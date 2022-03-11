#include <stdio.h>
#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

int	main(void)
{
	char	dst[16] = "Hello, world!";
	char	src[] = "Ah Ha!";

	printf("dst = :%s\n",dst);
	printf("dst_len: %zu, src_len: %zu\n", ft_strlen(dst), ft_strlen(src));
	printf("%zu\n", ft_strlcat(dst, src, 20));
	printf("%s\n", dst);
	printf("%zu\n", strlcat(dst, src, 20));
	printf("%s", dst);
	return (0);
}
