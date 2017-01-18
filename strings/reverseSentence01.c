
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
    char *word_begin;
    char *cur;
    word_begin = cur = str;
    
    while (*cur != '\0') {
        cur++;
        if (*cur == '\0') {
            reverseString(word_begin, cur - 1);
        } else if (*cur == ' ') {
            reverseString(word_begin, cur - 1);
            word_begin = ++cur;
        }
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