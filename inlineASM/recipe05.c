
#include <stdio.h>

// "&": early clobbers, content will change
//      before the completion of the function
static inline
char* mystrcpy(char *dest, const char *src)
{
    int d0, d1, d2;
    __asm__ __volatile__ ( "1:\tlodsb\n\t"
                           "stosb\n\t"
                           "testb %%al, %%al\n\t"
                           "jne 1b"
                           : "=&S" (d0), "=&D" (d1), "=&a" (d2)
                           : "0" (src), "1" (dest)
                           : "memory" 
                         );
    return dest;
}

int main()
{
    char src[] = {"MMYY1314"};
    char dest[100] = "";
    mystrcpy(dest, src);
    printf("%s\n", dest);
    return 0;
}