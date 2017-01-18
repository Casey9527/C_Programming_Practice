/*
    rotate elements in an array to right k times
    rotate one by one
    Time:  O(n*k)
    Space: O(1)
*/
#include <stdio.h>

void printArray(int arr[], int n);

void rightRotateByOne(int arr[], int n) {
    int i, tmp;
    tmp = arr[n - 1];
    for (i = n - 1; i >= 1; --i)
        arr[i] = arr[i-1];
    arr[i] = tmp;
}

void rightRotateByK(int arr[], int k, int n) {
    int i;
    for (i = 0; i < k; ++i)
        rightRotateByOne(arr, n);
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    scanf("%d", &k);
    printf("BEFORE: \n");
    printArray(arr, n);
    
    rightRotateByK(arr, k, n);
    
    printf("AFTER: \n");
    printArray(arr, n);
    
    return 0;
}