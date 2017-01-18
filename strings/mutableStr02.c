#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
 //   below definition creates a constant string
 //   char *mutable_str = "I'm your father!";
    
    char * mutable_str = (char *) malloc(sizeof(char) * 20);
    
    strcpy(mutable_str, "Yes. You're!");
    
    printf("%s\n", mutable_str);
    
    free(mutable_str);
    return 0;
}