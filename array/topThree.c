/*
    given an unsorted array with duplicates, 
    output the indices of top three valued elements
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct valueIndex {
    int val;
    int index;
}valueIndex;

void indicesOfTopThree(int arr[], int n) 
{
    if (n < 3)  return;
    
    valueIndex *top3 = (valueIndex *) malloc(sizeof(valueIndex) * 3);
    valueIndex *first, *second, *third, *tmp;
    first  = top3;
    second = (top3 + 1);
    third  = (top3 + 2);
    
    first->val = second->val = third->val = INT_MIN;
    first->index = second->index = third->index = -1;
    
    int i;
    for (i = 0; i < n; ++i) {
        if (arr[i] > first->val) {
            tmp = third;
            third = second;
            second = first;
            
            first = tmp;
            first->val = arr[i];
            first->index = i;
        } else if (arr[i] > second->val) {
            tmp = third;
            third = second;
            
            second = tmp;
            second->val = arr[i];
            second->index = i;
        } else if (arr[i] > third->val) {
            third->val = arr[i];
            third->index = i;
        }
    }
    printf("first <%d, %d>, second <%d, %d>, third <%d, %d>\n", 
            first->val, first->index,
            second->val, second->index,
            third->val, third->index);
    free(top3);
}

int main() 
{
    int arr[] = {1, 1, 1, 8, 5, 6, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    indicesOfTopThree(arr, size);
    return 0;    
}