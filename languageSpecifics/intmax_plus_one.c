#include <limits.h>
#include <stdio.h>

int main(void)
{
	printf("INT_MAX + 1: %d\n", (unsigned) INT_MAX + 1);
//	printf("INT_MAX + 1: %d\n", (unsigned) (INT_MAX + 1));
	printf("INT_MAX + 1: %u\n", (unsigned) INT_MAX + 1);
	return 0;
}
