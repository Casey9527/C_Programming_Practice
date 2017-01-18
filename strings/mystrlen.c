
#include <stdio.h>


size_t mystrlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int main()
{
    char str1[] = "";
    char str2[] = "kexin";
    
    printf("strlen(str1): %d\n", (int) mystrlen(str1));
    printf("strlen(str2): %d\n", (int) mystrlen(str2));
    
    return 0;
}
