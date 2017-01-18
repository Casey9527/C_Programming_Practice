#include <stdio.h>

void swap(int a[], int index1, int index2)
{
    int tmp = a[index1];
    a[index1] = a[index2];
    a[index2] = tmp;
}

void printArray(int arr[], int size)
{   
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int a[], int n)
{
    int swapped;
    int i, j;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;    // not swapped
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}