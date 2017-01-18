
#include <stdio.h>

void matrixTranspose(int* ar1, int* ar2, int n, int r, int c)
{
    int i, j, tmp;
    
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            *(ar2 + n*j + i) = *(ar1 + n*i + j);
        }
    }
}

int main()
{
    int ar1[10][10] = {0};
    int ar2[10][10] = {0};
    
    int r, c;
    printf("Input m and n: \n");
    scanf("%d", &r);
    scanf("%d", &c);
    
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &ar1[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", ar1[i][j]);
        printf("\n");
    }
    
    matrixTranspose((int *)ar1, (int *)ar2, 10, r, c);

    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", ar2[i][j]);
        printf("\n");
    }
    
    return 0;
}
