#include <stdio.h>
#include <assert.h>

char* mystrstr(char* haystack, char* needle)
{
    assert(haystack != NULL && needle != NULL);

    char *src = haystack;
    char *dst = needle;
    
    while (*haystack != '\0') {
        if (*dst == '\0') {         /* whole string match */
            return haystack;    
        } else if (*src == '\0') {  /* the source is not long enough  */
            // printf("haystack is shorter: it's a substring of needle\n"); // "hello" "helloworld"
            return NULL;
        } else if (*dst == *src) {  /* current character match */
            dst++;
            src++;
        } else {                    /* character not match, backtracking */
            src = ++haystack;
            dst = needle;
        }
    }
    if (*dst != '\0') {     /* if needle is longer than haystack */
        // printf("haystack is shorter: it's not a substring of needle\n"); // "hello" "worldworld"
        return haystack;
    } else {                /* if both haystack and needle are  */
        // printf("both strings are empty\n");
        return NULL;        /* empty strings. i.e. '\0'         */
    }
}

int main(int ac, char *av[])
{
    if (ac != 3) {
        printf("USAGE: %s haystack needle\n", av[0]);
        return -1;
    }

    char *pos = mystrstr(av[1], av[2]);
    if (pos != NULL) {
        printf("%s\n", pos);
    } else {
        printf("not found\n");
    }

    return 0;
}