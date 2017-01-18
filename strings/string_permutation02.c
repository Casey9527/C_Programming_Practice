#include <stdio.h>

void swap(char *s, int index1, int index2)
{
    char temp;
    temp = s[index1];
    s[index1] = s[index2];
    s[index2] = temp;
}

void permute(char *s, int l, int r)
{
    if (l == r) {
        printf("%s\n", s);
        return;
    }
    
    int i;
    for (i = l; i <= r; i ++) {
        swap(s, i, l);
        permute(s, l + 1, r);
        swap(s, i, l);
    }
}

int
main()
{
    char str[5] = "kexin";
    
    char out[5] = "";
    
    permute(str, 0, 4);
    
    return 0;
}