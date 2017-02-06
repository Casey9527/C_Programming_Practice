#include <stdio.h>

int countSetBits(int n) {
    unsigned int count = 0;
    while (n) {         /* non-zero: there exists a rightmost set bit */
        count ++;       
        n &= (n - 1);   /* unset the rightmost set bit 
                           n-1 would toggle all bits from the rightmost set bit (included) to right end */
    }
    return count;
}

int main() {
    int i = 9;
    printf("%d", countSetBits(i));
    getchar();
    return 0;
}
