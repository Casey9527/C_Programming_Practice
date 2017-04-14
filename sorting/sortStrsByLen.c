#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define MAXLEN 20

int compare (const void * a, const void * b) {
    size_t fa = strlen((const char *)a);
    size_t fb = strlen((const char *)b);
    return (fa > fb) - (fa < fb);
}

int main(int argc, const char * argv[]) {
    char arr[ROWS][MAXLEN] = {
        "wa",
        "wh",
        "ba",
        "fo"
    };
    qsort(arr, ROWS, MAXLEN, compare);

    printf("first string: %s\n", arr[0]);

    return 0;
}