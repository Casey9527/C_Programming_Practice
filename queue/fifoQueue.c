
#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 5

typedef struct queue {
    int q[QUEUESIZE+1];     /* body of queue */
    int first;              /* position of first element */
    int last;               /* position of last element */
    int count;              /* number of queue elements */
} queue;


init_queue(queue *q) {
    q->first = 0;
    q->last = QUEUESIZE - 1;
    q->count = 0;
}

enqueue(queue *q, int x) {
    if (q->count >= QUEUESIZE) {
        printf("Warning: queue overflow enqueue x=%n", x);
    } else {
        q->last = (q->last + 1) % QUEUESIZE;
        q->q[q->last] = x;
        q->count += 1;
    }
}

int dequeue(queue *q) {
    int x;
    if (q->count <= 0)  printf("Warning: empty queue dequeue.\n");
    else {
        x = q->q[q->first];
        q->first = (q->first + 1) % QUEUESIZE;
        q->count += 1;
    }
    return (x);
}

int empty(queue *q) {
    if (q->count <= 0) return 1;
    else return 0;
}

print_queue(queue *q) {
    int i, j;
    i = q->first;
    while (i != q->last) {
        printf("%c", q->q[i]);
        i = (i + 1) % QUEUESIZE;
    }
    printf("%2d", q->q[i]);
    printf("\n");
}
