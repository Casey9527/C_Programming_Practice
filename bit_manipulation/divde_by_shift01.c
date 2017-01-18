
#include <stdio.h>
#include <limits.h>

#define abs(x)  (x < 0) ? (-x) : (x)

int divide_by_shift(int dividend, int divisor)
{
    if (divisor == 0)   return INT_MAX;
    if (divisor == -1 && dividend == INT_MIN)    return INT_MAX;
    
    long pDividend = abs((long)(dividend));
    long pDivisor = abs((long)(divisor));
    
    int ret = 0;
    while (pDividend >= pDivisor) {
        // calculate num of left shifts
        int shift = 0;
        while (pDividend >= (pDivisor << shift)) {
            shift ++;
        }
        
        ret += 1 << (shift - 1);
        pDividend -= (pDivisor << (shift - 1));
    }
    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        return ret;
    else
        return -ret;
}



int
main(int ac, char *av[])
{
    int dividend = atoi(av[1]);
    int divisor = atoi(av[2]);
    
    printf("%d\n", divide_by_shift(dividend, divisor));
    
    return 0;
}