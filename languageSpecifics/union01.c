
/*
    Why we use union in Embedded System Programming?
    Reason 1: access individual bytes from a long type
*/
#include <stdio.h>

typedef union
{
    struct  {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
    unsigned int dword;
} HW_Register;

int main()
{
    HW_Register reg;
    reg.dword = 0x12345678;
    
    printf("reg.dword: 0x%x\n", reg.dword);
    printf("bytes.byte1: 0x%x\n", reg.bytes.byte1); // 0x78
    printf("bytes.byte2: 0x%x\n", reg.bytes.byte2); // 0x56
    printf("bytes.byte3: 0x%x\n", reg.bytes.byte3); // 0x34
    printf("bytes.byte4: 0x%x\n", reg.bytes.byte4); // 0x12
    return 0;
}

