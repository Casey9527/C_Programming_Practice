
#include <stdio.h>

int main(void)
{
	unsigned long a = -1;
	int b;

	b = a;

	printf("width of a: %d\n", (int)sizeof(a));
	printf("width of b: %d\n", (int)sizeof(b));
	printf("b: %d\n", b);

	return 0;
}
