#include <stdio.h>

int main()
{
	short int i = -127;	// 1111 1111 1000 0001
	short int j = +127;	// 0000 0000 0111 1111
	// h acts as length modifier for (unsigned) short int 
	// specify the length of i that can be printed is 4 bytes
	printf("short int -127 is %hx in hex\n", i);

	unsigned int k;

	k = i;
	printf("unsigned int k is %08x in hex\n", k);

	k = j;
	printf("unsigned int k is %08x in hex\n", k);

	return 0;
}