#include <stdio.h>

void printBinary(int n) {
    int i, j;
    char s[33];
    s[32] = '\0';
    for (i = 0, j = 31; i < 32 && j >= 0; i++, j--) {
        if (n & 1)
            s[j] = '1';
        else
            s[j] = '0';
        n >>= 1;
    }
    printf("%s\n", s);
}

/* represent by two's complement */
int main() {
    int arr[] = {-1, 1, 100, 65535, 2147483647, -2147483647, -2147483648};
    int i, size = sizeof(arr)/sizeof(arr[0]);
    for (i = 0; i < size; ++i)
        printBinary(arr[i]);
    return 0;
}