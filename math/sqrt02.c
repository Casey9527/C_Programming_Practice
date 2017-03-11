
#include <stdio.h>

#define ABS(val) ((val < 0) ? (-val) : (val))

double mySqrt(int n)
{
    if (n <= 0) return -1.0;
    double right = (double) n;
    double left  = 0.0;
    double middle;
    
    while (ABS(right - left) > 1e-15) {
        middle = left + (right - left) / 2.0;
        if ((double) n / middle == middle) {
            return middle;
        } else if ((double) n / middle > middle) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return middle;
}

int main()
{
    int n = 2;
    printf("sqrt(n): %g\n", mySqrt(n));
    return 0;
}