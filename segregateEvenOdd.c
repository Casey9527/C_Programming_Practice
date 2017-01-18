/*
    segregate an array results in all even numbers followed by odd numbers

*/
#include <stdio.h>

void segregateEvenOdd(int arr[], int size) {
    int left = 0, right = size - 1, tmp;
    
    while (left < right) {
        while (arr[left] % 2 == 0 && left < right)
            left++;
        while (arr[right] % 2 == 1 && left < right)
            right--;
        if (left < right) {
            tmp = arr[left];
            arr[left++] = arr[right];
            arr[right--] = tmp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
 
    segregateEvenOdd(arr, arr_size);
 
    printf("Array after segregation ");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
 
    return 0;
}