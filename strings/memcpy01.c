/*  */

#include <stdio.h>
#include <string.h>

void myMemcpy(void *dest, void* src, size_t n) {
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    int i;
    for (i = 0; i < n; i++)
        cdest[i] = csrc[i];
}

int main() {
    char csrc[] = "GeeksforGeeks";
    char cdest[100];
    myMemcpy(cdest, csrc, strlen(csrc) + 1);
    printf("copied string is: %s\n", cdest);
    
    int isrc[] = {10, 20, 30, 40, 50};
    int n = sizeof(isrc)/sizeof(isrc[0]);
    int idest[n], i;
    myMemcpy(idest, isrc, sizeof(isrc));
    printf("copied array is: ");
    for (i = 0; i < n; ++i)
        printf("%d ", idest[i]);
    printf("\n");
    return 0;
}