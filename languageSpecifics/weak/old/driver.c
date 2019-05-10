#include <stdio.h>

void __attribute__((weak)) foo()
//void foo()
{
	printf("foo from old directory\n");
}
