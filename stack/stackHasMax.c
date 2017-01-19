/**
 *   implement a stack that can do push(), pop(), max() in O(1) time. 
 *   stack is implemented using linked list
 *   max() should return the node (not value) containing max value;
 */

#include <stdio.h>
#include <stdlib.h>

/* linked list node definition */
typedef struct Node {
    int key;
    struct Node *next;
    struct Node *max;
} Node;

/* create node dynamically */
Node* createNode(int data)
{
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->key = data;
    tmp->next = tmp->max = NULL;
    return (tmp);
}

/* stack implemented by linked list */
typedef struct Stack {
    Node *top;
    int count;
    int capacity;
} Stack;

/* create stack dynamically */
Stack *createStack(int cap) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;
    s->count = 0;
    s->capacity = cap;
    return (s);
}

int isEmpty(Stack *s)
{
    return s->count == 0;
}

int isFull(Stack *s)
{
    return s->count == s->capacity;
}

void push(Stack *s, int val)
{
    Node *node = createNode(val);
    if (isFull(s)) {
        printf("stack full\n");
        return;
    }
    // link
    node->next = s->top;
    // set max
    if (s->top == NULL || 
        node->key >= s->top->max->key) 
    {
        node->max = node;
    } else {
        node->max = s->top->max;
    }
    // update
    s->top = node;
    s->count++;
}

/* pop the top (free it and return its key value) */
int pop(Stack *s)
{
    if (isEmpty(s)) {
        printf("stack empty\n");
        return -1;
    }
    Node *old_top = s->top;
    int result = old_top->key;
    s->top = s->top->next;
    s->count--;
    free(old_top);
    return result;
}

Node* peek(Stack *s)
{
    if (isEmpty(s)) {
        printf("stack empty\n");
        return NULL;
    }
    return s->top;
}

/* return the node which has maximum key value */
Node* max(Stack *s)
{
    if (isEmpty(s)) {
        printf("stack empty\n");
        return NULL;        
    }
    return s->top->max;
}

int main()
{
    int array[] = {1, 2, 3, 3, 4, 9, 5, 6, 2};
    int size = sizeof(array) / sizeof(array[0]);
    /* create a stack */
    Stack *s = createStack(32);
    int i;

    printf("Pushing...:\n");
    for (i = 0; i < size; i ++) {
        printf("PUSH: %d\n", array[i]);
        push(s, array[i]);
        printf("MAX: %d\n", max(s)->key);
    }

    printf("\nPoping...:\n");
    for (i = 0; i < size; ++i) {
        printf("MAX:  %d\n", max(s)->key);
        printf("POP:  %d\n", pop(s));
    }
    return 0;
}

