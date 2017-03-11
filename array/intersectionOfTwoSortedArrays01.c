// 5:11 - 5:32

#include <stdio.h>
#include <stdlib.h>

void intersection(int *a, int n1, int *b, int n2)
{
    int i, j;
    i = j = 0;
    
    while (i < n1 && j < n2) {
       // printf("a[%d]: %d, b[%d]: %d\n", i, a[i], j, b[j]);
        if (i != 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }
        
        if (j != 0 && b[j] == b[j - 1]) {
            j++;
            continue;
        }
        
        if (a[i] == b[j]) {
            printf("%d\n", a[i]);
            i++;
            j++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 1, 1, 3, 4, 5, 6, 7, 8};
    int b[] = {-3, -2, 1, 1, 2, 3, 3, 5, 5, 6};
    
    intersection(a, sizeof a / sizeof a[0], b, sizeof b / sizeof b[0]);
    
    return 0;
}

/*

void intersection(int *a, int n1, int *b, int n2)
{
    int i, j;
    i = j = 0;
    
    while (i <= n1 && j <= n2) {
        if (a[i] == a[j]) {
            if (i != 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            } else if (j != 0 && a[j] == a[j - 1]) {
                j++;
                continue;
            } else {
                printf("%d ", a[i]);
                i++;
                j++;
            }
        } else if (a[i] > a[j]) {
            j++;
        } else {
            i++;
        }
    }
    printf("\n");
}


*/
