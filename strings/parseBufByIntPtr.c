/**
 * qualcomm interview question:
 *
 * Parse an continuous memory into a byte array using 
 * a word pointer with some area are not readable  
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* parse_buffer(int *buf, int size)
{
	char* bytes = (char *) malloc(sizeof(int) * size);
	assert(bytes != NULL);

	int i = 0;
	// suppose the local machine is little-endian
	for ( ; i < size; ++ i) {
		bytes[4 * i + 0] = buf[i] & 0xFF;
		bytes[4 * i + 1] = ( buf[i] >> 8  ) & 0xFF;
		bytes[4 * i + 2] = ( buf[i] >> 16 ) & 0xFF;
		bytes[4 * i + 3] = ( buf[i] >> 24 ) & 0xFF;
	}

	return bytes;
}

int main()
{
	int A[] = {0x12345678, 0x78563412, 0x11223344, 0x44332211};

	int *pasred = (int *) (parse_buffer(A, sizeof(A)/sizeof(A[0])));

	int i;
	for (i = 0 ; i < 4; i ++)
		printf("0x%x\n", pasred[i]);

	return 0;
}	