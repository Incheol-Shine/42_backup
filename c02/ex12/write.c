#include <stdio.h>
#include <unistd.h>

int main()
{
    char c = 'a';
    char *ptr = &c;
    char **ptr2 = &ptr;

    printf("%p\n", ptr);
    // write(1, ptr2, 1);
    printf("%d\n",sizeof(ptr)); // 주소의 크기는 8바이트
    printf("%d ",(char *)(ptr2));
    return 0;
}