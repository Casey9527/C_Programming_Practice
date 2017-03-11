/*
    while(condition) {
       statement(s);
    }

The condition may be any expression, and true is any nonzero value. 
The loop iterates while the condition is true.

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    while (-1) {
        printf("while(-1) is true\n");
        exit(0);
    }
    printf("while(-1) is false\n");
    return 0;
}