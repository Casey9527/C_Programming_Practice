

#include <stdio.h>

//#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

#define mysizeof(X) \
{ \

typeof(X) x;\

(char *)(&x+1) - (char *)(&x);\

}


int main()
{
    double x;
    printf("%d", my_sizeof(x));
    getchar();
    return 0;
}