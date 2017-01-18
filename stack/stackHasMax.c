
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
    struct Node *max;
} Node;

Node* newNode(int data)
{
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->key = data;
    tmp->next = tmp->max = NULL;
    return (tmp);
}

typedef struct Stack {
    Node *top;
    int count;
    int capacity;
} Stack;

Stack *newStack(int cap) {
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

void push(Stack *s, Node *node)
{
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

Node* pop(Stack *s)
{
    if (isEmpty(s)) {
        printf("stack empty\n");
        return NULL;
    }
    Node *result = s->top;
    s->top = s->top->next;
    s->count--;
    return result;
}

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
    Node *node1 = newNode(1);
    Node *node2 = newNode(2);
    Node *node3 = newNode(3);
    Node *node4 = newNode(3);
    Node *node5 = newNode(4);
    Node *node6 = newNode(9);
    Node *node7 = newNode(5);
    Node *node8 = newNode(6);
    Node *node9 = newNode(2);
    
    
    Stack *s = newStack(32);
    push(s, node1);
    push(s, node2);
    push(s, node3);
    push(s, node4);
    push(s, node5);
    push(s, node6);
    push(s, node7);
    push(s, node8);
    push(s, node9);
    
    Node *tmp;
    
    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);
    
    
    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);    
    
    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);


    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);

    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);

    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);
    
    
    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);
    
    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);

    printf("max: %d\n", max(s)->key);
    tmp = pop(s);
    printf("pop: %d\n-------------------\n", tmp->key);
    
    return 0;
}


