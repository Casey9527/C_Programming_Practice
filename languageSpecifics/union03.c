
/*
    use union to handle unknown data type
    this is useful when you create a stack, whose key can be various types
*/

#include <stdio.h>

typedef enum { INTEGER, STRING, REAL, POINTER } Type;

typedef struct
{
    Type type;
    union {     /* use union to handle unknown data type */
        int integer;
        char *string;
        float real;
        void *pointer;
    } x;
} Value;


int main()
{
    Value v;
    v.type = INTEGER;
    v.x.integer = 5;
    return 0;
}