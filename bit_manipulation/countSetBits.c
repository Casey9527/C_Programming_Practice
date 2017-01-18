#include <stdio.h>

int countSetBits(int n) {
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int i = 9;
    printf("%d", countSetBits(i));
    getchar();
    return 0;
}