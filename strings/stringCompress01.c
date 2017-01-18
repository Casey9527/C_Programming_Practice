
#include <stdio.h>
#include <string.h>

void stringCompress(char *src) {
    int count;
    int len = strlen(src);
    
    int i, j = 0;
    
    for (i = 0; i < len; ++i) {
        printf("%c", src[i]);
        count = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }
        printf("%d", count);
    }
    printf("\n");
}

int main() {
    char str[] = "geeksforgeeks";
    stringCompress(str);
    return 0;
}