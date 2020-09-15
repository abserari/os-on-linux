#include <stdio.h>

// 1 little endian, 0 big endian
int checkCPUendian() {
    union
    {
        unsigned int  a;
        unsigned char b;
    } c;
    c.a = 1;
    return 1 == c.b;
}

int main() {
    if (checkCPUendian()) {
        printf("little\n");
    }else {
        printf("big\n");
    }

    char a[] = "0123456789abcdef";
    printf("%p\t %c\t %p\n", a, *(a+1), a-1);
    
    return 0;
}