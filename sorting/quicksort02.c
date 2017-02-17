
#include <stdio.h>

/**
 *
 * always select the A[len - 1] as pivot
 *
 * http://quiz.geeksforgeeks.org/quick-sort/
 *
 **/

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *A, int low, int high)
{	
	int i = low - 1;		// index to store the elements should be on the left of pivot
	int pivot = A[high];
	int j;
	for (j = low ; j <= high - 1; j ++) {
		if (A[j] <= pivot) {
			i ++;
			swap(&A[j], &A[i]);
		}
	}
	swap(&A[++ i], &A[high]);
	return i;
}


// quicksort(A, 0, len - 1)
void quicksort(int *A, int low, int high)
{
	if (low < high) {
		int pos = partition(A, low, high);
		quicksort(A, low, pos - 1);
		quicksort(A, pos + 1, high);
	}
}

int main()
{
	int A[] = {1, 2, 3, 4, 5, 6};
	int B[] = {6, 5, 4, 3, 2, 1};
	int C[] = {2, 1, 3, 4, 6, 5};
	int D[] = {4, 5, 6, 1, 2, 3};

	quicksort(A, 0, 5);
	quicksort(B, 0, 5);
	quicksort(C, 0, 5);
	quicksort(D, 0, 5);

	int i;
	printf("  A B C D\n");
	for (i = 0; i < 6; i ++) {
		printf("%d %d %d %d %d\n", i, A[i], B[i], C[i], D[i]);
	}
	return 0;
}
