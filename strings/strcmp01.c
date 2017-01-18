
/*  myStrcmp()
 *  > 0: s1 larger than s2
 *  < 0: s1 less than s2
 *  = 0: s1 equals s2
 */
#include <stdio.h>
#include <stdlib.h>

int myStrcmp(const char *s1, const char *s2) {
    for ( ; *s1 == *s2; s1++, s2++)
	    if (*s1 == '\0')
	        return 0;
    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}

int main() {
    char s1[] = {"IM Mm"};
    char s2[] = {"IM YY"};
    int ret = myStrcmp(s1, s2);
    if (ret > 0) {
        printf("s1 larger than s2\n");
    } else if (ret == 0) {
        printf("s1 equals s2\n");
    } else {
        printf("s1 less than s2\n");
    }
    
    return 0;
}


