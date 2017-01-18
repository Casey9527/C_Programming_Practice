

// dynamic allocation for 2d arrays
// suppose the 2d array is m*n
int** allocate2D(int m, int n)
{
    int **arr2D;
    arrayPtrRef = (int* *) malloc(sizeof(int *) * m);
    int i;
    for(i == 0; i < m; i++) {
        array2D[i] = (int *) malloc(sizeof(int) * n);
    }
    return arr2D;
}

// deallocation
void deallocate2D(int* *arr2D, int m)
{
    for (i = 0; i < m; i++) {
        free(arr2D[i]);
    }
    free(arr2D);
}


int*** allocate3D(int a, int b, int c)
{
    int ***arr3D;
    int i, j, k;
    
    arr3D = (int ***) malloc(a * sizeof(int **));
    
    for (i = 0; i < a; i++) {
        arr3D[i] = (int **) malloc(b * sizeof(int *));
        for (j = 0; j < b; j++) {
            arr3D[i][j] = (int *) malloc(c * sizeof(int));
        }
    }
    return arr3D;
}

void deallocate3D(int*** arr3D, int a, int b)
{
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++)
            free(arr3D[i][j]);
        free(arr3D[i]);
    }
    free(arr3D);
}
/*
layout of 3d array

    0       1       . . .         b-1
0   0..c-1  0..c-1  0..c-1        0..c-1

1

.
.
.

a-1

*/