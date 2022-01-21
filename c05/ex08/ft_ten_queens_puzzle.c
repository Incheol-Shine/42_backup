#include <unistd.h>
#include <stdio.h>
int     ft_ten_queen_puzzle(void);
int     recursive(int *arr, int r, int c, int cnt);
void    print_board(int *arr);
int     is_right_place(int *arr, int r, int c);
int     ft_abs(int nb);

int ft_abs(int nb)
{
    if (nb < 0)
        return (-nb);
    else
        return (nb);
}

void    print_board(int *arr)
{
    int     i;
    char    c;

    i = 0;
    while (i < 10)
    {
        c = arr[i] + '0';
        write(1, &c, 1);
        i++;
    }
    write(1, "\n", 1);
}

int is_right_place(int *arr, int r, int c)
{
    int i;

    if (arr[c] != 0)
        return (0);
    i = 0;
    while (i < 10)
    {
        if (ft_abs(r - arr[i]) == ft_abs(c - i))
            return (0);
        i++;
    }
    return (1);
}

int recursive(int *arr, int r, int c, int cnt)
{
    if (r == 10)
    {
        print_board(arr);
        cnt++;
        return (cnt);
    }
    else
    {
        while (c < 10)
        {
            if (is_right_place(arr, r, c))
            {
                printf("r: %d, c: %d\n");
                arr[c] = r;
                print_board(arr);
                cnt = recursive(arr, r + 1, 0, cnt);
                return (cnt);
            }
            c++;
        }
        arr[r] = 0;
    }
}
int ft_ten_queen_puzzle(void)
{
    int arr[10];
    int i;

    i = 0;
    while (i < 10)
    {
        arr[i] = 0;
        i++;
    }
    recursive(arr, 0, 0, 0);
}

int main(void)
{
    // int arr[10] = {1,0,0,0,0,0,0,0,0,0};
    printf("%d", ft_ten_queen_puzzle());
    // printf("%d", is_right_place(arr, 1, 2));
    return (0);
}