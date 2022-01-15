#include <stdio.h>
#include <stdlib.h>
void print_bord(int **bord, int n);

void test(int **bord);

void test(int **bord)
{
	int test_arr[4][4] ={{1,2,3,4},{2,3,4,1},{3,4,1,2},{4,1,2,3}};

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            bord[i][j] = test_arr[i][j];
        }
    }
}

void print_bord(int **bord, int n)
{	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d", bord[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int **bord = NULL;
	int n = 4;

	bord = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		bord[i] = (int*)malloc(sizeof(int)*5);
	
	test(bord);
	print_bord(bord, n);
}
