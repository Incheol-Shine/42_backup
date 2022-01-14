#include <string.h>
#include <stdio.h>

int main(void)
{
    char str1[] = "asdfakdkd";
    char str2[] = "asdfsfkdk";

    printf("%d\n", strncmp(str1, str2, 0));
    return (0);
}