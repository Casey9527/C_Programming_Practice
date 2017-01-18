
#include <stdio.h>

void myStrcpy(char *des, const char *src)
{
    if (*des == '\0' || *src == '\0')
        return;
//    myStrcpy(des++, src++);
    myStrcpy(des + 1, src + 1);
    *des = *src;
}

int main()
{
    char s1[6] = "abcde";
    char s2[7] = "123456";
    
    myStrcpy(s1, s2);
    
    printf("%s\n", s1);
    printf("%s\n", s2);
    
    return 0;
}