
#include <stdio.h>


void foo(int *a[][3])
{
	a[0][2] = (int *)11;
	a[1][2] = (int *)12;
}

int main(void)
{
	int *A[2][3] = {NULL};
	foo(A);

	printf("A[0][2]: %p\n", A[0][2]);
	printf("A[1][2]: %p\n", A[1][2]);

	return 0;
}
