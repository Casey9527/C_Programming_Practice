/*
    find the only two elements in an array that doesn't appear twice
*/

#include <stdio.h>
#include <stdlib.h>

void get2NonRepeatingNos(int arr[], int n, int *x, int *y) {
    int xor = arr[0];   // hold xor of all elements
    int set_bit_no;     // have only single set bit of xor
    int i;
    *x = 0;
    *y = 0;
    
    for (i = 1; i < n; ++i)
        xor ^= arr[i];
    // get the rightmost set bit
    set_bit_no = xor & ~(xor - 1);
    /* now divide elements into two sets by comparing set
       bit of xor with bit at the same position in each element. */

    for (i = 0; i < n; ++i) {
        if (arr[i] & set_bit_no)
            *x = *x ^ arr[i];
        else
            *y = *y ^ arr[i];
    }
}

int main()
{
  int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
  int *x = (int *)malloc(sizeof(int));
  int *y = (int *)malloc(sizeof(int));
  get2NonRepeatingNos(arr, 8, x, y);
  printf("The non-repeating elements are %d and %d", *x, *y);
  getchar();
}