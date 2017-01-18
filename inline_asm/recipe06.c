
#include <stdio.h>

#define mov_blk(src, dest, numwords) \
__asm__ __volatile__ (                                          \
                       "cld\n\t"                                \
                       "rep\n\t"                                \
                       "movsl"                                  \
                       :                                        \
                       : "S" (src), "D" (dest), "c" (numwords)  \
                       : "%ecx", "%esi", "%edi"                 \
                       )

int main(void)
{
    int src[]  = {1, 2, 3};
    int dest[3] = {0};
    int numwords = 2;
    mov_blk(src, dest, numwords);
    int i;
    for (i = 0; i < 3; ++i)
        printf("%d ", dest[i]);
    printf("\n");
    return 0;
}


