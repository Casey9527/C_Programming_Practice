/**
 * aligned_malloc()/aligned_free(): wrapper for malloc()/free()
 * 
 * allocate @size bytes and return starting address 
 * which is aligned with @alignment bytes. And can be freed
 * in a correct way.
 *
 * Different from alignedMalloc02.c, who  uses simple 
 * addition/substraction to locate the aligned address, 
 * here we use bitwise operators to achieve this. Due to
 * this, the alignment cannot be random number but power
 * of two.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void* aligned_malloc(size_t size, size_t alignment) {
    
    if (size <= 0 || alignment <= 0)    return NULL;

    void *p1;   // original address
    void *p2;   // aligned address
    size_t offset = alignment - 1 + sizeof(void *);

    p1 = (void *) malloc(sizeof(size_t) * (size + offset));
    
    if (p1 == NULL) return NULL;

    p2 = (void *)(((size_t)(p1) + offset) & ~(alignment - 1));
    
    // *((void* *)(p2 - 1)) = p1;
    ((void* *)(p2))[-1] = p1;

    // debug
    printf("p1: %p, p2: %p\n", p1, p2);
    return p2;
}

void aligned_free(void *p) {
    // debug
    printf("p1: %p, p2: %p\n", ((void* *)p)[-1], p);
    free(((void **)p)[-1]);
}

void main(int ac, char *av[]) {
    if (ac != 3) {
        printf("USAGE: %s size alignment\n", av[0]);
        return;
    }

    int *p = aligned_malloc(atoi(av[1]), atoi(av[2]));
    assert(p != NULL);
    aligned_free(p);
}