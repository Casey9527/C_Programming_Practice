
/*  myStrcmp()
 *  > 0: s1 larger than s2
 *  < 0: s1 less than s2
 *  = 0: s1 equals s2
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int mystrcmp(const char *s1, const char *s2) {
    assert(s1 != NULL && s2 != NULL);

    while (*s1 !='\0' && *s1 == *s2) {
        s1 ++, s2 ++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

int main(int ac, char *av[]) {
    if (ac != 3) {
        printf("USAGE: %s string1 string2\n", av[0]);
        return -1;
    }
    int ret = mystrcmp(av[1], av[2]);
    if (ret > 0) {
        printf("%s is larger than %s\n", av[1], av[2]);
    } else if (ret == 0) {
        printf("%s equals to %s\n", av[1], av[2]);
    } else {
        printf("%s is smaller than %s\n", av[1], av[2]);
    }
    
    return 0;
}


