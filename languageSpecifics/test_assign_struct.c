
#include <stdio.h>

struct struct_a {
	int a;
	int b;
};

int main(void)
{
	struct struct_a a = {.a = 1, .b = 2};
	struct struct_a b;

	b = a;

	printf("b.a: %d b.b: %d\n", b.a, b.b);
	return 0;
}
