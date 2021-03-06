
#include <bits/stdc++.h>
using namespace std;

/* utility function to find median of two integers */
float MO2(int a, int b) {
    return (a + b) / 2.0;
}

/* utility function to find median of three integers */
float MO3(int a, int b, int c) {
    return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

/* utility function to find median of four integers */
float MO4(int a, int b, int c, int d) {
    int Max = max(a, max(b, max(c, d)));
    int Min = min(a, min(b, min(c, d)));
    return (a + b + c + d - Max - Min) / 2.0;
}

// Utility function to find median of single array
float medianSingle(int arr[], int n)
{
   if (n == 0)
      return -1;
   if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
   return arr[n/2];
}

float findMedianUtil(int A[], int N, int B[], int M) {
    if (N == 0) /* if the smaller is empty, return median from second array */
        return medianSingle(B, M);
    if (N == 1) {   /* the smaller only have one element */
        // CASE 1:
        if (M == 1)
            return MO2(A[0], B[0]);
        
        // CASE 2: if the larger array has odd number of elements
        // A = {9} B = {5, 8, 10, 20, 30}
        // A = {1}
        if (M & 1)
            return MO2(B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]));
        // CASE 3: if the larger array has even number of elements
        return MO3(B[M/2], B[M/2 - 1], A[0]);
    }
    
    else if (N == 2) {
        // CASE 4: if the larger array also has two elements
        if (M == 2)
            return MO4(A[0], A[1], B[0], B[1]);
        
        // CASE 5: if the larger array has odd number of elements
        // median would be one of the following three elements:
        // 1. middle element of larger array
        // 2. Max of first element of smaller array and element
        //    just before the middle in bigger array
        // 3. Min of second element of smaller array and element
        //    just after the middle in bigger array
        if (M & 1) 
            return MO3(B[M/2], 
                       max(A[0], B[M/2 - 1]), 
                       min(A[1], B[M/2 + 1])
                      );
    
        return MO4(B[M/2], 
                   B[M/2 - 1], 
                   max(A[0], B[M/2 - 2]), 
                   min(A[1], B[M/2 + 1])
                  );
    }
    int idxA = (N - 1) / 2;
    int idxB = (M - 1) / 2;
    
    /* if A[idxA] <= B[idxB], then median must exist in
       A[idxA....] and B[....idxB] */
    if (A[idxA] <= B[idxB])
        return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA);
    
    /* if A[idxA] > B[idxB], then median must exist in
       A[...idxA] and B[idxB....] */
    return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA );
}



float findMedian(int A[], int N, int B[], int M) {
    if (N > M)
        return findMedianUtil(B, M, A, N);
    return findMedianUtil(A, N, B, M);
}

int main() {
    int A[] = {900};
    int B[] = {5, 8, 10, 20};
 
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);
 
    printf("%f\n", findMedian( A, N, B, M ) );
    return 0;
}