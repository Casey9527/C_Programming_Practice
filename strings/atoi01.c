
#include <stdlib.h>
#include <ctype.h>

int myatoi(const char *s)
{
    int result = 0;
    int sign = 1;   
    
    if (s == NULL) {
        return -1;
    }
    
    if (*s == '-') {
        sign = -sign;
        s++;
    }
    
    while (*s != '\0' && isdigit(*s)) {
        result = result * 10 + (*s - '0');
        s++;
    }
    return sign * result;
}
