
#include <stdio.h>

#define ABS(val) ((val < 0) ? (-val) : (val))

double mySqrt(int n)
{
    if (n <= 0) return 0;
    double epsilon = 1e-15;
    double t = n;
    
    while (ABS(t - n/t) > epsilon*t) {
        t = (t + n/t) / 2.0;
    }
    return t;
}

int main()
{
    int n = 2;
    printf("%g\n", mySqrt(n));
    return 0;
}

