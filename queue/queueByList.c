#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void enqueue(queue *q, int val) {
    if (q == NULL) {
        printf("enqueue failed. q is nil\n");
        return;
    }    
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = val;
    // add it into the exisint list
    if (!q->front) {
        q->front = new_node;
    }
    new_node->next = q->rear;
    q->rear = new_node;
}

void dequeue(queue *q) {
    node *last_front, *p;
    if (!q) {
        printf("dequeue failed. already empty\n");
        return;
    }
    last_front = q->front;
    p = q->rear;
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        while (p && p->next && p->next != q->front)
            p = p->next;
        q->front = p;
        q->front->next = NULL;
    }
    free(last_front);
}

int getFront(queue *q) {
    if (!q || !q->front)  {
        printf("getFront failed. q or q->front is nil\n");
        return;
    }
    return q->front->data;
}


void printQueue(queue *q) {
    if (!q) return;    
    node *p = q->rear;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    if (q->front)
        printf("front: %d\n", q->front->data);          
    if (q->rear)
        printf("rear: %d\n", q->rear->data);
}

queue* initQueue() {
    queue* q = (queue *) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return (q);
}

int main() {
    queue *q = initQueue();
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    printQueue(q);
    
    dequeue(q);
    printQueue(q);
    
    dequeue(q);
    printQueue(q);
    
    dequeue(q);
    printQueue(q);
    
    dequeue(q);
    printQueue(q);
    
    return;
}