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

typedef char uint8_t;

#define LSB(k, n) ((k) & ((1 << (n)) - 1))
#define MSB(k, n) LSB((k) >> (8 - (n)), n)

void decode_print(uint8_t* data, int data_len)
{
    uint8_t i, h, l;
    uint8_t temp;    
    for (i = 0; i < data_len; i ++) {
        h = i % 8;    // get higher h bits of data[i-1]
        l = 7 - h;    // get lower  l bits of data[i]
        
        if (h == 0)         // i equals 0
            temp = LSB(data[i], l) << h;
        else if (l == 0)    // i equals 7
            temp = data[i];
        else
            temp = ( LSB(data[i], l) << h ) | MSB(data[i - 1], h);

        printf("%x\n", temp);
    }
}



int main()
{
    uint8_t decoded[8] = {
     0xb4, 0x6a, 0x5f, 0x48, 
     0x45, 0x42, 0x41, 0x55
    };
    
    decode_print(decoded, 8);
    return 0;
}

    /*
    
    input[0] = 0x34 =>   0 0110100
    input[1] = 0x55 =>   0  101010 1
    input[2] = 0x7C =>   0   11111 01
    input[3] = 0x42 =>   0    1000 010
    input[4] = 0x54 =>   0     101 0100
    input[5]             0      10 01000
    input[6]             0       1 010000
    input[7]             0         0100000
        
    */
