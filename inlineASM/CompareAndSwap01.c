// implement a Compare-And-Swap in C
/*
int actual = *ptr;
if (actual == old)
    *ptr = new;
return actual;
*/
char CompareAndSwap(int *ptr, int old, int new)
{
    unsigned char *ret;
    __asm__ __volatile__ (
        " lock\n"    
        " cmpxchgl %2, %1\n"    # if eax == dest, dest = src
                                # else eax = dest
        " sete %0\n"            # set ret 1 if equal, otherwise set as 0
        : "=q"(ret), "=m"(*ptr)
        : "r"(new), "m"(*ptr), "a"(old)
        : "memory"
    );
}