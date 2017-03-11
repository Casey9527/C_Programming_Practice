/* 
    coding question in the second interview with VMware
*/
/*
    Given an array of integers, write a function that 
    returns the third largest value in the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b)   (a > b ? a : b)
#define MIN(a, b)   (a < b ? a : b)

// when *e > *t, we call this function
void rearrange(int *f, int *s, int *t, int e)
{
    *f = MAX(e, MAX(*f, MAX(*s, *t)));
    *t = MIN(e, MIN(*f, MIN(*s, *t)));
    *s = MAX(e, *s);   
    printf("%d %d %d\n", *f, *s, *t);
    return;
}

void getThirdLargest(int arr[], int size)
{
    // array may be not sorted, duplicates may also exist
    // binary maximum heap, insert all integers into the heap,
    // then get the maximum from the heap, until the third largest
    // is meet
    // time (n), space(n)
    if (size <= 0)  return;
    
    int first, second, third;
    first  = second = third = INT_MIN;
    
    int i;
    for (i = 0; i < size; ++i) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third) {
            third = arr[i];
        }
    }
    printf("first: %d, second: %d, third: %d\n", first, second, third);
}


int main() 
{
    int arr[] = {1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    getThirdLargest(arr, size);
    return 0;
}





