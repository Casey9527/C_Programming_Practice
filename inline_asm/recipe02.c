#include <stdio.h>

#define my_init 15

int main(void)
{
    int my_var  = 10;
    
    // atomic addition
    __asm__ __volatile__ ("lock       ;\n"
                          "addl %1, %0;\n"
                          : "=m" (my_var)
                          : "ir" (my_init), "m" (my_var)
                          : /* no clobber-list */
                         );
    printf("my_var + my_init = %d\n", my_var);
    return 0;
}