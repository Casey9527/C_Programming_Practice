/*
    http://www.geeksforgeeks.org/array-rotation/
    
    rotate elements in an array to right k times
    A juggling algorithm
    Time:  O(n)
    Space: O(1)
*/
#include <stdio.h>

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

void rightRotateByK(int arr[], int k, int n) {
    int i, j, tmp, _gcd;
    _gcd = gcd(k, n);
    for (i = 0; i < _gcd; ++i) {
        tmp = arr[n - i];
        for (j = n - i - _gcd - 1; j >= 0; j -= _gcd)
            arr[j + _gcd] = arr[j]; 
        arr[j + _gcd] = tmp;
    }
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