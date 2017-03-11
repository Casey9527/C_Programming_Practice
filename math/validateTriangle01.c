
#include <stdio.h>

void isValidTriangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("invalid\n");
        return;
    }
    if (a + b > c && a + c > b && b + c > a)
        printf("valid\n");
    else
        printf("invalid\n");
}

int main()
{
    isValidTriangle(3,4,5);
    isValidTriangle(5,5,5);
    isValidTriangle(3,3,5);
    isValidTriangle(3,3,6);
    isValidTriangle(3,3,12);
    isValidTriangle(1,1,0);
    isValidTriangle(0,0,0);
    isValidTriangle(-1,0,0);
    isValidTriangle(-1,0,2);
    return 0;
}