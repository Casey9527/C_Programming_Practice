/*              best        average     worst   worst space
    Quicksort	O(nlog(n))	O(nlog(n))	O(n^2)	O(log(n))
*/
#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);    // index of smaller elements
    int j;
    for (j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[high]);   // move the pivot number right of smaller elements
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;    
}