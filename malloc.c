/*
    http://www.inf.udec.cl/~leo/Malloc_tutorial.pdf
    
    write a malloc in C
    main features:
    - allow malloc(), free(), calloc(), realloc()
    - make use of available free blocks
    - merging freed blocks to avoid fragmentation
    - alignment
    - efficient realloc()
*/

#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/* block struct */
struct s_block { /* the metadata block is already aligned to the integer size */
    size_t size;
    struct s_block *next;
    struct s_block *prev;
    int free;
    void *ptr;
    /* A pointer to the allocated block */    
    char data[1];
};

typedef struct s_block* t_block;    // hide the pointer using typedef

#define META_SIZE (20)  // aligned to four  todo?

#define align4(x) (((((x)-1)>>2)<<2)+4)

void *base = NULL;

/* find a fitting chunk, return NULL if none where found */
t_block find_block(t_block *last, size_t s) {
    t_block b = base; // global
    while (b && !(b->free && b->size >= s)) {
        *last = b;
        b = b->next;
    }
    return (b);
}

/*
    add a new block at the of heap
    return NULL id things go wrong
    size s already aligned
*/
t_block extend_heap(t_block last, size_t s) {
    int sb;
    t_block b;
    b = sbrk(0);
    sb = (int) sbrk(META_SIZE + s);
    if (sb < 0)
        return (NULL);
    b->size = s;
    b->next = NULL;
    b->prev = last;
    b->ptr  = b->data;
    if (last)
        last->next = b;
    b->free = 0;
    return (b);
}


/*  split block according to size
    The b block must exist
    size s is already aligned
*/
void split_block(t_block b, size_t s) {
    t_block new;
    new = (t_block)(b->data + s);
    new->size = b->size - s - META_SIZE;
    new->next = b->next;
    new->prev = b;
    new->free = 1;
    new->ptr  = new->data;  // todo?
    b->size = s;
    b->next = new;
    if (new->next)
        new->next->prev = new;
}


void *malloc (size_t size) {
    t_block b, last;
    size_t s;
    s = align4(size);   /* align the wanted size */
    if (base) {         /* check if it is first time to allocate */
        /* First find a block */
        last = base;
        b = find_block(&last, s);
        if (b) {        /* found a fitting block */
            /* can we split */
            if ((b->size - s) >= META_SIZE + 4)
                split_block(b, s);
            b->free = 0;
        } else {        /* no fitting block, extend the heap */
            b = extend_heap(last, s);
            if (!b)
                return (NULL);
        }
    } else {            /* first time to call malloc() */
        b = extend_heap(NULL, s);
        if (!b) {
            return (NULL);
        base = b;
    }
    return (b->data);
}

/*
    calloc(): assign number*size, initialize to 0
    trick: since size is aligned to four, we can
    initialize by every four bytes
*/
void *calloc(size_t number, size_t size) {
    size_t *new;
    size_t s4, i;
    new = malloc(number * size);
    if (new) {
        s4 = align4(number * size) << 2;
        for (i = 0; i < s4; ++i) {
            new[i] == 0;
        }
    }
    return (new);
}

/* get the block from the meta part */
t_block get_block(void *p) {
    char *tmp;
    tmp = p;
    return (p = tmp -= META_SIZE);
}

/* Valid addr for free */
int valid_addr(void *p) {
    if (base) {
        if (p > base && p < sbrk(0)) {
            return (p == (get_block(p))->ptr);
        }
    }
}

/*  merge current free block with its next block
    if next block is free
*/
t_block fusion(t_block b) {
    if (b->next && b->next->free) {
        b->size += META_SIZE + b->next->size;
        b->next = b->next->next;
        if (b->next) {
            b->next->prev = b;
        }
    }
    return (b);
}

/* 
    free():
    - validate the address
    - try to fusion with its prev or next block
    - free the end of heap
*/
void free(void *p) {
    t_block b;
    if (valid_addr(p)) {
        b = get_block(p);
        b->free = 1;
        /* fusion with previous if possible */
        if (b->prev && b->prev->free) {
            b = fusion(b->prev);
        }
        if (b->next)    /* try to fusion the next block */
            fusion(b);  
        else {          /* free the end of heap */
            if (b->prev)
                b->prev->next = NULL;
            else    /* no more block */
                base = NULL;
            brk(b);
        }
    }
}


void copy_block(t_block src, t_block dst) {
    int *sdata, *ddata;
    size_t i;
    sdata = src->ptr;
    ddata = dst->ptr;
    for (i = 0; i*4 < src->size && i*4 < dst->size; ++i)
        ddata[i] = sdata[i];
}

void *realloc(void *p, size_t size) {
    size_t s;
    t_block b, new;
    void *newp;
    if (!p)
        return (malloc(size));

    if (valid_addr(p)) {
        s = align4(size);
        b = get_block(p);
        if (b->size >= s) {
            if (b->size - s >= (META_SIZE + 4)) {
                split_block(b, s);
            }
        } else {        /* fusion with next block and split as needed */
            if (b->next && b->next->free
                && (b->size + META_SIZE + b->next->size) >= s) {
                    fusion(b);
                    if (b->size - s > = (META_SIZE + 4))
                        split_block(b, s);
            } else {    /* reallocate a new block */
                newp = malloc(s);
                if (!newp)
                    return (NULL);
                new = get_block(newp);
                copy_block(b, new);
                free(p);
                return (newp);
            }
        }
        return (p);
    }   /* end of valid_addr(p) if...else... */
    return (NULL);
}