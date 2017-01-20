/*
When sending SMS messages, all characters can be represented using ASCII encoding, 
which contains 127 characters, that can be represented using 7 bits (2^7 = 128). 
Now given an array of variables encoded using ASCII code, stored in UINT8_t, 
they can be packed into a byte buffer OUTPUT in the following format:

uint8_t *input, *output;

input[0] = 0x34 =>   0 0110100
input[1] = 0x55 =>   0  101010 1
input[2] = 0x7C =>   0   11111 01
input[3] = 0x42 =>   0    1000 010
input[4] = 0x54 =>   0     101 0100

output[0] =   1 0110100  : lower 7 bits from input[0]’s bit 0-6, bit    7 comes from input[1]’s bit 0
output[1] =   01 101010  : lower 6 bits from input[1]’s bit 1-6, bits 6-7 come  from input[2]’s bit 0-1
output[2] =   010 11111  : lower 5 bits from input[2]’s bit 2-6, bits 5-7 come  from input[3]’s bit 0-2
output[3] =   0010 1000  : lower 4 bits from input[3]’s bit 3-6, bits 4-7 come  from input[4]’s but 0-3


Now, given an a byte buffer that contains packed 7bits ASCII code, print out value of each 7 BIT variable:

void decode_print(uint8_t* data, int data_len)

*/

#include <stdio.h>
#include <stdlib.h>
typedef char uint8_t;

/* get lower n bits */
#define LSB(k, n) ((k) & ((1 << (n)) - 1))
/* get higher n bits */
#define MSB(k, n) LSB((k) >> (8 - (n)), n)


    /*
    
    input[0] = 0x34 =>   0   0110100 nil ----------->
    input[1] = 0x55 =>   0    101010 1   -----------> output[0] =        1 0110100   =>   0xb4 
    input[2] = 0x7d =>   0     11111 01  -----------> output[1] =       01 101010    =>   0x6a
    input[3] = 0x42 =>   0      1000 010 -----------> output[2] =      010 11111     =>   0x5f
    input[4] = 0x54 =>   0       101 0100 ----------> output[3] =     0100 1000      =>   0x48
    input[5] = 0x48 =>   0        10 01000 ---------> output[4] =    01000 101       =>   0x45
    input[6] = 0x50 =>   0         1 010000 --------> output[5] =   010000 10        =>   0x42
    input[7] = 0x20 =>   0       nil 0100000 -------> output[6] =  0100000 1         =>   0x41
    input[8] = 0x44      0   1000100 nil -----------> output[7] = nil      nil       =>   0x0
    
    */

void decode_print(uint8_t* data, int data_len)
{
    uint8_t i, h, l;
    uint8_t temp;    
    for (i = 0; i < data_len; i ++) {
        h = i % 8;    // get higher h bits of data[i-1]
        l = 7 - h;    // get lower  l bits of data[i]
        

        if (i == 0) {
            temp = LSB(data[i], l);
        } else {
            /* the every 8th output should be zero */
            if (h == 7 && data[i] != 0) {
                printf("output[%d] = %x, is a wrong input.\n", i, data[i]);
                exit(-1);
            }
            temp = (LSB(data[i], l) << h) | (MSB(data[i - 1], h)); 
        }

        printf("input[%d] = 0x%x\n", i, temp);
    }
}

int main()
{
    uint8_t decoded[8] = {
     0xb4, 0x6a, 0x5f, 0x48, 
     0x45, 0x42, 0x41, 0x0
    };
    
    decode_print(decoded, 8);
    return 0;
}
