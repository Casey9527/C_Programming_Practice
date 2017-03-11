
#include <stdio.h>


size_t mystrlen(const char *s)
{
    size_t cnt = 0;
    while ( *s ++ != '\0') {
        cnt ++;
    }
    return cnt;
}

int main()
{
    char str1[] = "";
    char str2[] = "kexin";
    
    printf("strlen(str1): %d\n", (int) mystrlen(str1));
    printf("strlen(str2): %d\n", (int) mystrlen(str2));
    
    return 0;
}
