
#include <stdio.h>

void binaryArraySort(int a[], int n)
{
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] > a[j]) {
            a[i++] = 0;
            a[j--] = 1;
        } else if (a[i] == 0 && a[j] == 0) {
            i++;
        } else if (a[i] == 0 && a[j] == 1) {
            j--;
        } else {
            i++;
            j--;
        }
    }
}

int main() {
    
    int a[] = {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1};
    int n = sizeof a / sizeof a[0];
    printf("sorted:\n");
    binaryArraySort(a, n);
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");
    return 0;
}