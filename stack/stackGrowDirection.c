/*
    determine whether OS stack grows up or down in plain C
*/
#include <stdio.h>

void stackGrowDirection(int *x) {
    int y;
    if (!x) {
        stackGrowDirection(&y);
    } else {
        if (&y > (int *) x) {
            printf("grow up...\n");
        } else {
            printf("grow down...\n");
        }
    }
}

int main() {
    int *a = NULL;
    stackGrowDirection(a);
    return;
}