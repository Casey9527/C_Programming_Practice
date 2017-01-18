#include <stdio.h>
#include <string.h>

int main()
{
    char mutable_str[] = "I'm your father!";
    
    strcpy(mutable_str, "Yes. You're!");
    
    printf("%s\n", mutable_str);
    
    return 0;
}