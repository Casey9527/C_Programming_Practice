
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int a[], int index1, int index2);

void shuffleCards(int a[], int n) 
{
    srand(time(NULL));
    int i;
    for (i = n - 1; i > 0; i--) {
        swap(a, i, rand() % (i + 1));
    }
}