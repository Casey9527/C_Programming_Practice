
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* mystrcat(char* dest, const char* src)
{
    assert(dest != NULL && src != NULL);
    strcpy(dest + strlen(dest), sr);
    return dest;
}

int main()
{
    char src[]    = "ranran is here!";
    char dest[100] = "where is ranran? ";
    printf("%s\n", dest);
    
    mystrcat(dest, src);
    
    printf("%s\n", dest);
}
