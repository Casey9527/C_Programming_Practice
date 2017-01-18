typedef struct {
    int m;
    int n;
    int *data;
}Int2D;

Int2D arr2D = {2, 3};
arr2D.data = malloc(arr2D.m * arr2D.n * sizeof(*arr2D.data));


// arr3D[a][b][c]
typedef struct {
    int a;
    int b;
    int c;
    int *data;
}Int3D;

Int3D arr3D = {2, 3, 4};
arr3D.data = malloc(arr3D.a * arr3D.b * arr3D.c * sizeof(*arr3D.data));

// access arr3D[x][y][z]
// becomes:
arr3D.data[ (arr3D.c * arr3D.b) * x + arr3D.c * y + z ];

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