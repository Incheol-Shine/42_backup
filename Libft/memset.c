#include <stdio.h>
#include <string.h> 

int	main(void)
{
	int		arr[] = {1,2,3,4,5};
	char	str[] = "Hello, world!";
	int		src[] = {0, -1, -2};

	for (int i=0; i<5; i++)
		printf("%d ", arr[i]);
	printf("\n%s\n", str);
	
	memcpy(arr, src, 3*sizeof(int));
	memcpy(str, "Hi Hi", 5*sizeof(char));
	for (int i=0; i<5; i++)
		printf("%d ", arr[i]);
	printf("\n%s\n", str);
}
