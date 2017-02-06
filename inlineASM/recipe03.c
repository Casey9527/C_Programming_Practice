#include <stdio.h>

int main(void)
{
    int my_var  = 1;
    char cond = 0;
    
    // atomic addition
    __asm__ __volatile__ ("decl %0; sete %1"
                          : "=m" (my_var), "=q" (cond)
                          : "m" (my_var)
                          : "memory"
                         );
    printf("my_var = %d, cond = %d\n", my_var, cond);
    return 0;
}