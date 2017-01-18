
#include <stdio.h>

int main(void)
{
    int foo = 10, bar = 15;
    __asm__ __volatile__ ("addl %%ebx, %%eax"
                          :"=a"(foo)
                          :"0"(foo), "b"(bar)
                          );
    printf("foo + bar = %d\n", foo);
}
