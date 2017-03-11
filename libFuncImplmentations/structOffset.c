/*
   #define OFFSETOF(s, m) ((size_t)&(((s *)0)->m))
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct struc_x {
    int a;
    int b;
} struc_x;

int main() {
    struc_x *s = malloc(sizeof(struc_x));
    char *base;
    int offset;
    int *addr_b;
    /* initialize both memebers */
    s->a = 1;
    s->b = 2;
    /* get base address */
    base = (char *)s;
    /* get offset to member b */
    offset = offsetof(struc_x, b);
    /* compute address of member b */
    addr_b = (int *) (base + offset);
    /* write to member b via pointer */
    *addr_b = 10;
    printf("%d\n", s->b);
    return 0;
}