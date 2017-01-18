
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
    int sign = 1;
    if (n < 0) {
        sign = -sign;
        n = -n;
    }
    char str[100] = "";
    int i = 0;
    do {
        str[i++] = n%10 + '0';
    } while ((n /= 10) != 0);

    if (sign < 0) {
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse(str);
    printf("%s\n", str);
}

int main()
{
    int n = -987;
    decimal2binary(n);
    return 0;
}