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
    
    for (i = 0; i < n - 1; i++) {           // every iteration, we put a number at its correct position
                                            // i.e. we put a big number at somewhere rightside
                                            // i means # of items who already set on its correct position
        
        swapped = 0;                        // a flag to record whether we do swap in current iteration  
        for (j = 0; j < n - i - 1; j++) {   // swap on the remaing items. index range from i+1 to n-i-2
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);          
                swapped = 1;
            }
        }
        if (swapped == 0) {                 // no swapping in current iteration. stops here!
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
