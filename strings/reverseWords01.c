#include <stdio.h>
#include <stdlib.h>

void reverseString(char *left, char *right)
{
    char tmp;
    while (left < right) {
        tmp = *right;
        *right-- = *left;
        *left++ = tmp;
    }
}

void reverseWords(char *s)
{
    char *s0, *s1;
    s0 = s1 = s;
    
    while (*s1 != '\0') {
        s1++;
        if (*s1 != '\0' && *s1 == ' ') {
            reverseString(s0, s1 - 1);
            s0 = s1 + 1;
        }
    }
    reverseString(s, s1 - 1);
}

int main(int argc, char* *argv)
{
    if (argc != 2) {
        printf("usage: ./a.out <input string>\n");
        exit(0);
    }
    printf("before reversing:\n%s\n", argv[1]);
    reverseWords(argv[1]);
    printf("after reversing:\n%s\n", argv[1]);
    exit(0);
}