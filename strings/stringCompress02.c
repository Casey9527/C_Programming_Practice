#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_RLEN 50

char *encode(char *src) {
    int rLen;
    int len = strlen(src);
    char count[MAX_RLEN];
    
    char *dest = (char *) malloc(sizeof(char)*(len*2 + 1));
    
    int i, j = 0, k;
    for (i = 0; i < len; ++i) {
        dest[j++] = src[i];
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }
        // format the rLen to string, store at char array;
        sprintf(count, "%d", rLen);
        // copy the occurances in string format to dest buffer
        for (k = 0; *(count + k); ++k, ++j)
            dest[j] = count[k];
    }
    dest[j] = '\0';
    return dest;
}

int main() {
    char str[] = "geeeeeeeeeeeeeksforgeeks";
    char *res = encode(str);
    printf("%s\n", res);
    return 0;
}