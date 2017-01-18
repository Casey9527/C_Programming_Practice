#include <stdio.h>

int main()
{
    int result;
    
    result = -1 == 1;
    printf("result: %d\n", result); // result = 0
    
    result = 1 == 1;
    printf("result: %d\n", result); // result = 1
    
    return 0;
}