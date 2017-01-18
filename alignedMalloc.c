#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(size_t required_bytes, size_t alignment) {
    if (alignment < 0) {
        return NULL;
    }
    void *p1;   // original block
    void **p2;  // aligned block
    int offset = alignment - 1 + sizeof(void *);
    printf("sizeof(void *) is %d\n ", (int)sizeof(void *));
    if ((p1 = (void *) malloc(required_bytes + offset)) == NULL)
        return NULL;
    p2 = (void **)(((size_t)(p1) + offset) & ~(alignment - 1));
    
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *p) {
    /*
    void **p1;
    p1 = (void **)p;
    p1 = p1[-1];
    free(*p1);
    */
    free(((void **)p)[-1]);
}

void main(int argc, char *argv[]) {
    char **endptr;
    int *p = aligned_malloc(5, strtol(argv[1], endptr, 10));
    printf("%s: %p\n", argv[1], p);
    aligned_free(p);
}