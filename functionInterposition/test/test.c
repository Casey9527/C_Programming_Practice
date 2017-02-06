#include <stdio.h>
#include <stdlib.h>
int main()
{
    free(malloc(10));
    printf("hello world\n");
    return 0;
}