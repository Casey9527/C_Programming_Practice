#include <stdio.h>
#include <string.h>

void reverse(char *s)
{
    int left, right;
    left = 0;
    right = (int) strlen(s) - 1;
    char temp;
    while (left < right) {
        temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

void decimal2binary(int n)
{
    char str[100] = "";
    int i;
    int mask = 1;
    for (i = 0; i < 32; ++i) {
        if (n & mask) {
            str[i] = '1';
        } else {
            str[i] = '0';
        }
        mask <<= 1;
    }
    str[i] = '\0';
    reverse(str);
    printf("by decimal2binary: %s\n", str);
}

int main()
{
    int n = -987;
    printf("by printf: 0x%x\n", n);
    decimal2binary(n);
    return 0;
}