/*
    priority queue:
    1. insertion
    2. top item removal: highest priority element removed out first

    implementation:
    - use a dynamic array as a binary heap
    - stores integer priority and a character pointer
    - supports push and pop
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    char *data;
} node_t;

typedef struct {    // initialized to be all zeros
    node_t *nodes;
    int len;
    int size;
} heap_t;

void push(heap_t *h, int priority, char *data)
{
    if (h->len + 1 >= h->size) {
        h->size = h->size ? h->size * 2 : 4;
        h->nodes = (node_t *) realloc(h->nodes, h->size * sizeof(node_t));
    }
    int i = h->len + 1;     // insertion starts from nodes[1]
    int j = i / 2;
    
    // keep searching for leftmost parent with smaller priority
    while (i > 1 && h->nodes[j].priority > priority) {
        h->nodes[i] = h->nodes[j];
        i = j;
        j = j / 2;
    }
    h->nodes[i].data = data;
    h->nodes[i].priority = priority;
    h->len++;
}

char* pop(heap_t *h)
{
    int i, j, k;
    if (!h->len) {
        return NULL;
    }
    
    char *data = h->nodes[1].data;
    h->nodes[1] = h->nodes[h->len];
    h->len--;
    
    i = 1;
    
    while (1) {
        k = i;
        j = 2 * i;
        
        if (j <= h->len 
            && h->nodes[j].priority < h->nodes[k].priority)
        {
            k = j;
        }
        
        if (j + 1 <= h->len 
            && h->nodes[j + 1].priority < h->nodes[k].priority) 
        {
            k = j + 1;
        }
        
        if (k == i) {
            break;
        }
        h->nodes[i] = h->nodes[k];
        i = k;
    }
    h->nodes[i] = h->nodes[h->len + 1];
    return data;
}

int main () {
    heap_t *h = (heap_t *)calloc(1, sizeof (heap_t));
    push(h, 3, "Clear drains");
    push(h, 4, "Feed cat");
    push(h, 5, "Make tea");
    push(h, 1, "Solve RC tasks");
    push(h, 2, "Tax return");
    int i;
    for (i = 0; i < 5; i++) {
        printf("%s\n", pop(h));
    }
    return 0;
}