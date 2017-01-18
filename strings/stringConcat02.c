#include <stdio.h>
#include <stdlib.h>
int main() {
    char s1[] = "i'm mm! i love yy";
    char s2[] = "i'm yy! i love mm";
    int i = 0, j = 0;
    char *s = (char *) malloc(sizeof(s1) + sizeof(s2) + 1);
    
    while (s1[i]) {
        s[i] = s1[i];
        i++;
    }
    while (s2[j]) {
        s[i++] = s2[j++];
    }
    
    puts(s);
    free(s);
    return 0;
}