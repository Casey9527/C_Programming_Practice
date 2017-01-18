
#include <stdio.h>

void testEndianness()
{
    int x = 1;
    char *ptr = (char *)&x;
    if (*ptr == 0) {
        puts("big endian");
    } else {
        puts("little endian");
    }
}

int main()
{
    testEndianness();
    return 0;
}