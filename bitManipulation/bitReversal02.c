#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned int reverse_bits(unsigned int n)
{
    unsigned int count = sizeof(n) * 8;
    unsigned int ret = 0;

    while (n) {
        ret <<= 1;
        ret |= n & 1;
        n >>= 1;
        count--;
    }
    ret <<= count;
    return ret;
}

int main(int ac, char *av[])
{
    if (ac != 2) {
        printf("USAGE: %s number\n", av[0]);
        return -1;
    }
    assert(atoi(av[1]) >= 0);
    unsigned int x = atoi(av[1]);
    printf("x: 0x%x\n", x);
    printf("0x%x\n", reverse_bits(x));
    return 0;
}