
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int value)
{
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return (node);
}

Node *stack_top = NULL;

Node* cmpxchg(Node* *old_top_ref, Node* old_top, Node* new_top);

void push(int value)
{
    Node* node = newNode(value);
    Node* old_top;
    
    do {
        old_top = stack_top;
        node->next = old_top;
    } while (cmpxchg(&stack_top, old_top, node) != old_top);
}

Node* pop()
{
    Node* old_top;
    
    do {
        old_top = stack_top;
        if (old_top == NULL)    // if stack is empty
            return NULL;
    } while (cmpxchg(&stack_top, old_top, old_top->next));

    return old_top;
}

Node* cmpxchg(Node* *top_ref, Node* old_top, Node* new_top)
{
    Node* ret;
    
    __asm__ __volatile__ (
        "lock \n"
        "mov %0, %1\n"
        "cmpxchgl %2, %1\n"
        : "=q"(ret), "=m"(*top_ref)
        : "m"(*top_ref), "r"(new_top), "a"(old_top)
        : "memory");

    return ret;
}
