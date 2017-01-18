
#include <stdio.h>

unsigned leading_zero_naive1(int x)
{
    unsigned n = 0;
    const unsigned bits = sizeof(x) * 8;
    int i;
    for (i = 0; i < bits; ++i) {
        if (x < 0) break;
        n++;
        x <<= 1;
    }
    return n;
}

unsigned leading_zero_naive2(int x)
{
    unsigned n = 0;
    const unsigned bits = sizeof(x) * 8;
    int i;
    for (i = bits; --i; ) {
        if (x < 0) break;
        n++;
        x <<= 1;
    }
    return n;
}

unsigned leading_zero_naive3(int x)
{
    unsigned n = 0;
    if (x == 0) return sizeof(x) * 8;
    while (1) {
        if (x < 0) break;
        n++;
        x <<= 1;
    }
    return n;
}

// for 32-bit unsigned
unsigned leading_zero(unsigned x)
{
    unsigned n = 0;
    if (x <= 0x0000ffff) n += 16, x <<= 16;
    if (x <= 0x00ffffff) n +=  8, x <<= 8;
    if (x <= 0x0fffffff) n +=  4, x <<= 4;
    if (x <= 0x3fffffff) n +=  2, x <<= 2;
    if (x <= 0x7fffffff) n ++;
    return n;
}

int main()
{
    unsigned x = 0x007F0000;
    printf("%d\n", leading_zero(x));
    
    return 0;
}
