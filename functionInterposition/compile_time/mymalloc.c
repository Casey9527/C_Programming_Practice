#ifdef COMPILETIME

/* Compile-time interposition of malloc and free using C preprocessor
 * A local malloc.h file defines malloc (free) as wrappers mymalloc (myfree)
 * respectively
 */
 
#include <stdio.h>
#include <malloc.h>

/*
 * mymalloc - malloc wrapper function
 * goal: trace the addresses and sizes of the allocated 
 *       and freed blocks without modifying the source code.
 */
 
void *mymalloc(size_t size, char *file, int line)
{
    void *ptr = malloc(size);
    printf("%s:%d: malloc(%d)=%p\n", file, line, (int) size, ptr);
    return ptr;
}

void myfree(void *ptr, char *file, int line)
{
    free(ptr);
    printf("%s:%d: free(%p)\n", file, line, ptr);
}

#endif