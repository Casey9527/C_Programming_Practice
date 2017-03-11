/**
 *
 * This demos value of the comparisons
 * 
 * value of (-1 == 1) is 0
 * value of ( 1 == 1) is 1
 *
 **/

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