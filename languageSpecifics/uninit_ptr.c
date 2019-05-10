#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PAGEOFFSET 255
#define ArraySize 5
#define DWORD unsigned long

int main(void)
{
	char *p;

	printf("un-initialized ptr: %p\n", p);

	p = (char *)((intptr_t)p & PAGEOFFSET);

	printf("un-initialized ptr: %p\n", p);
//	DWORD tmp = (DWORD)malloc(ArraySize);


//	int *ptr = (int *)tmp;
	return 0;
}
