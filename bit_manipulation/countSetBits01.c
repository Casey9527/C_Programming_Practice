
#include <stdio.h>

unsigned count_set_bits(int x)
{
    unsigned count = 0;
    while (x) {     /* expression is true for any nonzero value */
        count++;
        x &= (x -1);
    }
    return count;
}

int main()
{
    int n = 0xFFFFFFFF;
    printf("%d\n", count_set_bits(n));
    return 0;
}