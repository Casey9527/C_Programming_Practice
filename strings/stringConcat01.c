#include <stdio.h>

int main() {
    char s1[100], s2[100];
    int i = 0, j = 0;
    printf("first string: \n");
    scanf("%s", s1);
    printf("second string: \n");
    scanf("%s", s2);
    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0')
        s1[i++] = s2[j++];
    s1[i] = '\0';
    puts(s1);
    return 0;
}