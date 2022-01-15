#include <stdio.h>
const int n2=5;
int g_ok[10][10];
int g_cnt=0;
int g_flag = 0;
int check(const int n,int r,int c,int ab[][n2]);
int check2(const int n,int r,int c,int ab[][n2]);

void dfs(int n,int r, int c,int ab[][n2],int d)
{  
    // printf("asdf");
    // printf("%d %d %d  ",r,c,g_flag);
    int tmp;
    if(g_flag)
        return;
    
    if (c == n && r == n-1)
    {
        // printf("%d",123);
        g_flag=1;
        // printf("\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",g_ok[i][j]);
            }
            printf("\n");
        }
        return ;
    }
    if (c == n)
    {
        r+=1;
        c=0;
    }
    if (r==n)
        return ;
    
    for (int i=1;i<=n;i++)
    {
        tmp = g_ok[r][c];
        g_ok[r][c] = i;

        // printf("%d %d %d %d  ",check(n,r,c,ab),r,c,i);
        // printf("\n%d %d %d\n",r,c,g_ok[r][c-1]);
        if (check(n,r,c,ab) && check2(n,r,c,ab) )
        {
            // printf("\n");
            
            // for(int i=0;i<n;i++)
            // {
                
            //     for(int j=0;j<n;j++)
            //     {
            //         printf("%d ",g_ok[i][j]);
            //     }
            //     printf("\n");
                
            // }
            // printf("g_cnt : %d ");            
            // g_cnt++;
            dfs(n,r,c+1,ab,i);
            // g_cnt--;
        }
        else
        {
            // printf("\n");
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<n;j++)
            //     {
            //         printf("%d ",g_ok[i][j]);
            //     }
            //     printf("\n");
                
            // }
            g_ok[r][c] = tmp;
        }
            
        
        
    }
    if (c == n)
    {
        r-=1;
        c=n-1;
    }
    
}
int check2(const int n,int r,int c,int ab[][n2])
{
    
    int ok[n];
    // printf("check2 : ");
    // if(g_ok[r][n-1] !=0)
    //     c = n-1;
    // if(g_ok[n-1][c] !=0)
    //     r = n-1;
    for(int i=0;i<n;i++)
    {
        ok[i]=0;
    }
    for(int j=0;j<=c;j++)
    {
        ok[g_ok[r][j]-1]++;
        // printf("%d %d " ,ok[g_ok[r][j]-1],g_ok[r][j]);
        // printf("%d ",g_ok[r][j]);
        if(ok[g_ok[r][j]-1]>=2)
        {
            
            // printf("false1");
            return 0;
        }
            
    }
    for(int i=0;i<n;i++)
    {
        ok[i]=0;
    }
    for(int j=0;j<=r;j++)
    {
        ok[g_ok[j][c]-1]++;
        if(ok[g_ok[j][c]-1]>=2)
        {
            // printf("false2");
            return 0;
        }
            
    }
    // printf("ok");
    return 1;
}
int check(const int n,int r,int c,int ab[][n2])
{
    
    int max = 0;
    int sum = 0;
    int min = 0;
    int sumup =0;
    int sumdown =0;
    int sumleft =0;
    int sumright =0;
    int ok[n];
    int flagc=0,flagr = 0,flag1=0,flag2=0;
    for(int j=0;j<=c;j++)
    {
        if (max < g_ok[r][j])
        {
            max = g_ok[r][j];
            sumleft++;
        }
        if (min < g_ok[r][n-j-1])
        {
            // printf("a");
            min = g_ok[r][n-j-1];
            sumright++;
        }
    }
    max =0;
    min=0;
    for(int i=0;i<=r;i++)
    {
        if (max < g_ok[i][c])
        {
            max = g_ok[i][c];
            sumup++;
        }
        if (min < g_ok[n-1-i][c])
        {
            min = g_ok[n-1-i][c];
            sumdown++;
        }
    }
    // printf("check : ");
    // printf("%d %d %d %d ",sumup,sumdown,sumleft,sumright);

    // if(n-1 == c)
    //     flagc = 1;
    // if(n-1 == r)
    //     flagr = 1;
    flagr=(sumright == ab[3][r]);
    flagc = (sumdown == ab[1][c]);
    flag1 = (sumleft <= ab[2][r]);
    flag2 =(sumup <= ab[0][c]);
    if(r == n-1 && c == n-1)
        return (flagr && flagc && flag1 && flag2);
    else if(r == n-1)
        return (flagc && flag1 && flag2);
    else if(c == n-1)
    {
        // printf("    %d %d %d %d   ",r,c,sumright,ab[3][r]);
        return (flagr && flag1 && flag2);
    }
    else 
        return (flag1 && flag2);

    

}

int main()
{
    int a;
    int ab[4][4]={{4,3,2,1},{1,2,2,2},{4,3,2,1},{1,2,2,2}};
    int cd[4][2] = {{2,1},{1,2},{2,1},{1,2}};
    int sky[4][5] = {{3,1,2,3,2},{2,5,1,2,3},{2,3,1,2,2},{4,1,3,2,2}};
    
    // dfs(4,0,0,ab,0);
    
    // printf("\n\n");
    int n = n2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            g_ok[i][j] = 0;
        }
    }
    g_ok[0][0] = 1;
    dfs(n,0,0,ab,0);
    // for(int i=0;i<4;i++)
    // {
        
    //     for(int j=0;j<4;j++)
    //     {
    //         printf("%d ",g_ok[i][j]);
    //     }
    //     printf("\n");
        
    // }
    // for(int i=0;i<4;i++)
    // {
    //     for(int j=0;j<4;j++)
    //     {
    //         printf("%c ",g_board[i][j]);
    //     }
    //     printf("\n");
    // }
}