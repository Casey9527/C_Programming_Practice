#include <stdio.h>

int isPostOrderOfBST(int arr[], int low, int high)
{
    if (low == high)    return 1;
    
    int i, j;
    for (i = low; i <= high && arr[i] < arr[high]; ++i);
    
    for (j = i; j <= high && arr[j] > arr[high]; ++j);
    
    if (j != high) 
        return 0;
    else
        return isPostOrderOfBST(arr, low, i - 1) &&
               isPostOrderOfBST(arr + i, i, j - 1);
}

int main()
{
   int arr[] = {1, 3, 2, 5, 4, 7, 7, 8, 6};
   int size = sizeof(arr) / sizeof(arr[0]);
   
   if (isPostOrderOfBST(arr, 0, size - 1)) {
       printf("yes\n");
   } else {
       printf("no\n");
   }
   
   return 0; 
}
