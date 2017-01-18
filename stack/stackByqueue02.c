/*
    implement a stack using two queues
    we make pop() costly in this implementation
*/

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

typedef struct stack {
    queue *q1;
    queue *q2;
} stack;

/* utility functions provided by queue */
void enqueue(queue *q, node *new_node) {
    if (q == NULL) {
        printf("enqueue failed. q is nil\n");
        return;
    }
    if (!q->front) {
        q->front = new_node;
    }
    new_node->next = q->rear;
    q->rear = new_node;
}

node* dequeue(queue *q) {
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
    return last_front;
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

/* stack utility functions supported by queue */
void push(stack *s, int val) {
    if (!s || !s->q2) {
        printf("failed to push. s or q2 is nil\n");
        return;
    }
    printf("PUSH: %d\n", val);
    node *tmp;
    queue *tmp_q;
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
    /* step1: enqueue it into q2 */
    enqueue(s->q2, new_node);
    /* step2: move everything from q1 to q2 */
    while (s->q1 && s->q1->front) {
        tmp = dequeue(s->q1);
        enqueue(s->q2, tmp);
    }
    /* step3: exchange queue names */
    tmp_q = s->q1;
    s->q1 = s->q2;
    s->q2 = tmp_q;
}

node* pop(stack *s) {
    if (!s || !s->q1) {
        printf("failed to pop. s or q1 is nil\n");
        return NULL;
    }
    return dequeue(s->q1);
}

int peek(stack *s) {
    if (!s || !s->q1 || !s->q1->front) {
        printf("failed to peek, stack is empty\n");
        return;
    }
    return s->q1->front->data;
}

stack* initStack() {
    stack *s = (stack *) malloc(sizeof(stack));
    s->q1 = initQueue();
    s->q2 = initQueue();
    return (s);
}

int main() {
    stack *s = initStack();
    node *tmp;
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    
    while ((tmp = pop(s)) != NULL) {
        printf("POP:  %d\n", tmp->data);
    }
    getchar();
    return 0;
}