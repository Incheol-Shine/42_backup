#include <string.h>
#include <stdio.h>
int main(void)
{
    char anna[] = "Do you wanna build a snowman?";
    char elsa[] = "snowyman";
    char *ptr;

    printf("%s",strstr(anna, elsa));
    return (0);
}