#include <stdio.h>
#include <stdlib.h>

/**
 *
 * always select the A[len/2] as pivot
 *
 * https://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
 *
 **/
void quicksort(int *A, int len)
{
	if (len <= 1) {
		return;
	}

	int pivot = A[len/2];
	int i, j, tmp;

	for (i = 0, j = len - 1; ; i ++, j --) {
		while (A[i] < pivot)	i ++;
		while (A[j] > pivot)	j --;

		if (i >= j) break;

		tmp  = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}

	quicksort(A, i);
	quicksort(A + i, len - i);
}

int main()
{
	int A[] = {1, 2, 3, 4, 5, 6};
	int B[] = {6, 5, 4, 3, 2, 1};
	int C[] = {2, 1, 3, 4, 6, 5};
	int D[] = {4, 5, 6, 1, 2, 3};

	quicksort(A, 6);
	quicksort(B, 6);
	quicksort(C, 6);
	quicksort(D, 6);

	int i;
	printf("  A B C D\n");
	for (i = 0; i < 6; i ++) {
		printf("%d %d %d %d %d\n", i, A[i], B[i], C[i], D[i]);
	}
	return 0;
}
