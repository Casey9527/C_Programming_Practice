#include <stdio.h>

int swap_bits(int n, int p1, int p2)
{
    int bit1 = ( n >> p1 ) & 1;
    int bit2 = ( n >> p2 ) & 1;
    
    int xor_bits = bit1 ^ bit2;
    
    int x = (xor_bits << p1) | (xor_bits << p2);
    
    return x ^ n;
}

int main(int ac, char *av[])
{
    int swapped = swap_bits(atoi(av[1]), atoi(av[2]), atoi(av[3]));
    printf("%d\n", swapped);
    return 0;
}