/*
 * You can use %zd or %zu to print out size_t type.
 */

#include <stdio.h>
#include <stdlib.h>

void main(int ac, char **av)
{
	printf("sizeof(int) is %zd\n", sizeof(int));
	printf("sizeof(long) is %zu\n", sizeof(long));
	return;
}
