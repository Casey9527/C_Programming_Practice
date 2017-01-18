#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int num, i, j, count = 0;
    scanf("%d", &num);
    int *isPrime = (int *) malloc(sizeof(int) * num);
    memset(isPrime, 1, sizeof(int)*num);
    
    for (i = 2; i*i <= num; ++i) {
        if (!isPrime[i])
            continue;
        for (j = i*i; j < num; j += i)  // mark 'q^2 + q' as false
            isPrime[j] = 0;
    }
    
    for (i = 2; i < num; ++i) {
        if (isPrime[i]) {
            count++;
            printf("%d ", i);
        }
    }
    
    printf("\n %d in total\n", count);
    free(isPrime);
    return 0;
}