/*
    rotate elements in an array to right k times
    use tmp array
    Time:  O(n)
    Space: O(k)
*/
#include <stdio.h>

void printArray(int arr[], int n);

void rightRotateByK(int arr[], int k, int n) {
    int i;
    int tmp[k];
    for (i = 0; i < k; ++i)
        tmp[i] = arr[n - k + i];
    for (i = n - 1; i >= k; --i)
        arr[i] = arr[i - k];
    for (i = 0; i < k; ++i)
        arr[i] = tmp[i];
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