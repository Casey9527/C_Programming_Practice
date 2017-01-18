#include <stdio.h>
#include <string.h>

void reverseString(char* start, char* end)
{
    char tmp;
    while (start < end) {
        tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
}

void reverseSentence(char *str)
{
    int start, end;
    start = end = 0;
    while (str[start] != '\0') {
        while (str[end] != ' ' && str[end] != '\0')
            end++;
        reverseString(str + start, str + end - 1);
        start = ++end;
    }

    reverseString(str, str + (size_t) strlen(str) - 1);
}

int main()
{
    char str[] = " Kexin Chen  lalala   ";
    reverseSentence(str);
    
    printf("%s\n", str);
    
    return 0;
}