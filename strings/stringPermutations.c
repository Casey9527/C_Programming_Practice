
#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char tmp;
    tmp = *x;
    *x  = *y;
    *y  = tmp;
}

/*
    l: starting index
    r: ending index
*/
void permute(char *s, int l, int r) {
    int i;
    if (l == r)
        printf("%s\n", s);
    else {
        for (i = l; i <= r; ++i) {
            swap((s+l), (s+i));
            permute(s, l+1, r);
            swap((s+l), (s+i)); // backtrack
        }
    }
}

int main() {
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}