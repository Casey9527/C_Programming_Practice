#include <stdio.h>

void strStr(char *haystack, char *needle) {
    int i = 0, j = 0;
    while (haystack[i]) {
        for (j = 0; haystack[i + j] && needle[j]; ++j) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (!needle[j]) {
            printf("there is a match\n");
            return;
        }
        i++;
    }
    printf("there is no match\n");
}

int main() {
    char *s1 = "I'm kexin chen, who are you?";
    char *s2 = "kexin chen  ";
    strStr(s1, s2);
    return 0;
}
