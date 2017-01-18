#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>


void * malloc(size_t size)
{
    static void * (*func) (size_t) = NULL;
    if (!func) {
        func = (void * (*)(size_t)) dlsym(RTLD_NEXT, "malloc");
    }
    
    void *ret = func(size);
    printf("malloc(%d) at %p\n", (int) size, ret);
    return ret;
}

void free(void * ptr)
{
    static void (*func1)(void *) = NULL;
    if (!func1) {
        func1 = (void (*)(void *)) dlsym(RTLD_NEXT, "free");
    }
    func1(ptr);
    printf("free(%p)\n", ptr);
}