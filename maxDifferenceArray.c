
/*
    
*/
#include <stdio.h>
#include <limits.h>

#define MAX(a, b) (a < b ? b : a)

int maxDiff(int arr[], int size) {
    int min_val = arr[0];
    int max_diff = INT_MIN;
    int i;
    for (i = 1; i < size; ++i) {
        if (arr[i] > min_val) {
            max_diff = MAX(arr[i] - min_val, max_diff);
        } else {
            min_val = arr[i];
        }
    }
    return max_diff;
}


int main() {
  int arr[] = {1, 2, 90, 10, 110};
  printf("Maximum difference is %d",  maxDiff(arr, 5));
  getchar();
  return 0;
}