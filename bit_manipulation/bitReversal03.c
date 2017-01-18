#include <stdio.h>

unsigned int reverseBits(unsigned int n)
{
    int result = 0;
    int i;
    for (i = 0; i < 32; i++) {
        result <<= 1;
        result |= n & 1;
        n >>= 1;
    }
    return result;
}

int main()
{
    unsigned int x = 2;
    printf("%u\n", reverseBits(x));
    return 0;
}