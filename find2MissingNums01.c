#include <stdio.h>
#include <math.h>

void find2Misses(int arr[], int n)
{
    int i;
    int a, b;    
    int sq_sum, sq_sum2;
    sq_sum = sq_sum2 = 0;
    
    int sum, sum2;
    sum = sum2 = 0;
    
    for (i = 1; i <= n; i++) {
        sum += i; 
        sq_sum += i*i;
    }
    
    for (i = 0; i < n - 2; i++) {
        sum2 += arr[i];
        sq_sum2 += arr[i] * arr[i];
    }
    
    b = (sum - sum2) - (int) sqrt((double)(2*sq_sum - 2*sq_sum2 - (sum - sum2)^2)) / 2; 
    a = (sum - sum2) - b;
    printf("a: %d, b: %d\n", a, b);
}

/*

(a + b) = sum -sum2

(a - b) = sqrt((a - b)^2) = sqrt(a^2 + b^2 - 2ab)

a^2 + b^2 = sq_sum - sq_sum2

2ab = (a + b)^2 - a^2 - b^2 = (sum - sum2)^2 - sq_sum + sq_sum2

(a - b) = sqrt(sq_sum - sq_sum2 - (sum - sum2)^2 + sq_sum - sq_sum2)
        = sqrt(2sqsum - 2sq_sum2 - (sum - sum2)^2)


((a + b) - (a - b)) / 2 = b

(a + b) - b = a

*/

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 10;
    find2Misses(a, n);
    return 0;
}