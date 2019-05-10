#include <stdio.h>

struct l3l4 {
	int a;
	int b;
	int c;
};

int main(void)
{

	printf("sizeof(int) on 64-bit machine: %d\n", (int)sizeof(int));
	printf("sizeof(struct l3l4) on 64-bit machine: %d\n", (int)sizeof(struct l3l4));

	return 0;
}
