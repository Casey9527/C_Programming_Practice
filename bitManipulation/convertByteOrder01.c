/**
 *
 * convert byte order on 32-bit machine
 * 
 * little-endian to big-endian or vice versa
 *
 */

#include <stdio.h>

unsigned convert_byte_order_32(unsigned x) 
{
    unsigned swapped;
    swapped = ( (x >> 24) & 0xff      ) |
    		  ( (x >> 8 ) & 0xff00    ) |
    		  ( (x << 8 ) & 0xff0000  ) |
    		  ( (x << 24) & 0xff000000);
    return swapped;
}

void main(void)
{
	unsigned original  = 0x12345678;
	unsigned converted = convert_byte_order_32(original);

	printf("original : 0x%x\nconverted: 0x%x\n", 
		    original, converted);
}
