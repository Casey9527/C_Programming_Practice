#include <stdio.h>

int countSetBits(int n) {
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int countFlippedBits(int a, int b) {
    return countSetBits(a ^ b);
}

int main() {
    printf("%d", countFlippedBits(0b1001001, 0b0010101));
    getchar();
    return 0;
}