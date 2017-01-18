#include <stdio.h>
#include <stdlib.h>

int isPostOrderOfBST(int *arr, int size)
{
    if (size < 2)   return 1;
    
    int rootVal = arr[size - 1];
    int i, j;
    for (i = 0; i < size && arr[i] < rootVal; ++i);
    
    for (j = i; j < size && arr[j] > rootVal; ++j);

    if (j != size - 1)
        return 0;
    else
        return isPostOrderOfBST(arr, i) && 
               isPostOrderOfBST(arr + i, j - i);
}

int main()
{
   int arr[] = {1, 3, 2, 5, 4, 7, 7, 8, 6};
   int size = sizeof(arr) / sizeof(arr[0]);
   
   if (isPostOrderOfBST(arr, size)) {
       printf("yes\n");
   } else {
       printf("no\n");
   }
   
   return 0; 
}

