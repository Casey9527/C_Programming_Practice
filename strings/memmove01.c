/* memmove() can handle cases when source and destination address
   have overlapping
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myMemmove(void *dest, void *src, size_t n) {
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    char *tmp = (char *) malloc(n);
    int i = 0;
    
    for (i = 0; i < n; ++i)
        tmp[i] = csrc[i];
    for (i = 0; i < n; ++i)
        cdest[i] = tmp[i];
    free(tmp);
}

int main() {
    char csrc[100] = "Geeksfor";
    myMemmove(csrc + 5, csrc, strlen(csrc) + 1);
    printf("%s\n", csrc);
    return 0;
}