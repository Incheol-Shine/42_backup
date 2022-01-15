#include <stdio.h>
int main(int argc, char * argv[])
{
	int i;
	int arr[20];

	printf("Hello, world \n");
	printf("argc=%d\n", argc);

	printf("%s\n",argv[1]);
	arr = input2arr(argv[1]);
	for (int i=0; i<20; i++)
	{
		printf("%d, ",arr[i]);
	}
	return 0;
}
