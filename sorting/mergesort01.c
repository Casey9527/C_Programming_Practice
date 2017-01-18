// 1:45 - 2: 35

#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int m, int n)
{
    int *tmp = (int *) malloc(sizeof(int) * n);
    int i, j, k;
    for (k = 0, i = 0, j = m; k < n; k++) {
        tmp[k]   = j == n ? arr[i++] 
                 : i == m ? arr[j++]
                 : arr[i] < arr[j] ? arr[i++]
                 :                   arr[j++];
    }
    
    for (i = 0; i < n; i++) {
        arr[i] = tmp[i];
    }
    free(tmp);
}

void mergesort(int *arr, int n)
{
    if (n < 2) {
        return;
    }
    int m = n / 2;
    mergesort(arr, m);
    mergesort(arr + m, n - m);
    merge(arr, m, n);
}

int main()
{
    int arr[] = {9, 5, 6, 7, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, n);
    
    int i;
    for (i = 0; i < n; ++i)
        printf("%d\n", arr[i]);
    return 0;
}

