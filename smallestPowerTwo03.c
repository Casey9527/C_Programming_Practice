#include <stdio.h>

unsigned int nextPowerOf2(unsigned int n) {
    unsigned int p = 1;
    int count = 0;
    while (p < n) {
        p <<= 1;
        count++;
    }
    return count;
}

/* Driver program to test above function */
int main() {
    unsigned int n = 17;
    printf("%d", nextPowerOf2(n));
    
    getchar();
    return 0;
}
