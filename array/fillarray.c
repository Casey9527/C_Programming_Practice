
#include <stdio.h>

void foo(int a[])
{
	a[0] = 0;
	a[1] = 1;
}

int main(void)
{
	int A[2] = {5, 5};
	foo(A);

	printf("A[0]: %d\n", A[0]);
	printf("A[1]: %d\n", A[1]);

	return 0;
}
