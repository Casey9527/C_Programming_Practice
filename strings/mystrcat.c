
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrcat(char* dest, const char* src)
{
    if (dest == NULL)
        return NULL;
    
    char *dest_end;
    dest_end = dest + strlen(dest);
    
    //*dest_end = 0;
    strcpy(dest_end, src);
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
