int check(int **bord,int n,int r,int c);

// int test_arr[4][4] ={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
int test_arr[4][4] ={{2,1},{1,2}};

int check(int **bord,int n,int r,int c)
{
    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=c; j++)
        {
            if(bord[i][j] != test_arr[i][j])
                return 0;
        }
    }
    return 1;
}