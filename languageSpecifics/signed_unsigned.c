#include <stdio.h>

#define SECONDS_PER_YEAR (60 * 60 * 24 * 365UL)

void foo(void)
{

	unsigned int a = 6;

	int b = -20;

	(a+b > 6) ? puts("> 6") : puts("<= 6");
}

int main(void)
{
	foo();
	printf("SECONDS_PER_YEAR: %lu\n", SECONDS_PER_YEAR);
	return 0;
}
