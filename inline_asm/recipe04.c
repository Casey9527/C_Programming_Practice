
#include <stdio.h>
// "Ir": pos is put in a reg, value ranges from 0-31 
// "cc": conidtion code register will be changed
int main()
{
    int ADDR = 0x0;
    int pos  = 31;
    __asm__ __volatile__ (   "btsl %1, %0"
                           : "=m" (ADDR)
                           : "Ir" (pos)
                           : "cc"
                         );
    printf("ADDR: 0x%x\n", ADDR);
    return 0;
}                     