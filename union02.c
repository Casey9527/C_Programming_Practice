
/*
    Why we use union in Embedded System Programming?
    Reason 2: bit modifier, can access any single bit in register/memory
*/

#include <stdio.h>

typedef union {
    unsigned char control_byte;
    struct {
        unsigned int nibble  : 4;
        unsigned int nmi     : 1;
        unsigned int enabled : 1;
        unsigned int fired   : 1;
        unsigned int control : 1;
    } bits;
} ControlRegister;

int main()
{
    ControlRegister ctrl_reg;
    ctrl_reg.control_byte = 0b10101100;
    printf("bits.nibble: %d\n", ctrl_reg.bits.nibble);      // 12
    printf("bits.nmi: %d\n", ctrl_reg.bits.nmi);            // 0
    printf("bits.enabled: %d\n", ctrl_reg.bits.enabled);    // 1
    printf("bits.fired: %d\n", ctrl_reg.bits.fired);        // 0
    printf("bits.control: %d\n", ctrl_reg.bits.control);    // 1
    return 0;
}
