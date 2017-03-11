#include <stdio.h>
#include <ctype.h>

int myatoi(const char *s)
{
    int result = 0;
    int sign = 1;   
    
    if (s == NULL) {
        return -1;
    }
    
    if (*s == '-' || *s == '+') {
        sign = (*s == '-') ? -1 : 1;
        s++;
    }
    
    while (*s != '\0' && isdigit(*s)) {
        result = result * 10 + (*s - '0');
        s++;
    }
    return sign * result;
}

int main(int ac, char *av[])
{
    if (ac != 2) {
        printf("USAGE: %s number\n", av[0]);
        return 0;
    }

    printf("The number you enter is: %d\n", myatoi(av[1]));

    return 0;
}