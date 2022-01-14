#include <string.h>
#include <stdio.h>

int main(void)
{
    char str1[] = "AZAZ";
    char str2[] = "AAZA";

    printf("%d", strcmp(str1,str2));
    return (0);
}