/*
    test what would happen if i++ happens as the last statement
*/

#include <stdio.h>

int i = 5;

void test()
{
    printf("inside test(), i is: %d\n", i++);
}

int main()
{
    printf("in main(), before test(), i is: %d\n", i);
    test();
    printf("in main(), after  test(), i is: %d\n", i);
    return 0;
}