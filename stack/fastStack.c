/*
    implement a stack in that push(), pop(), max()
    can be done in O(1) ime. 
    stack should be implemented using linked list
    max() should return the node (not value) containing max value;
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    struct node *max;
    int data;
};

struct stack {
    struct node *top;
};

void push(struct stack *s, int val) {
    struct node *tmp;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("failed to allocate new node\n");
        getchar();
        exit(0);
    }
    
    new_node->data = val;
    
    if (s->top == NULL) {
        s->top = new_node;          /* update s->top */
        new_node->max = new_node;   /* fill the new node */
        new_node->next = NULL;
    } else {
        if (s->top->max->data > new_node->data) { /* update max node */
            new_node->max = s->top->max;
        } else {
            new_node->max = new_node;
        }
        new_node->next = s->top;    /* update s->top */
        s->top = new_node;
    }
}

int pop(struct stack *s) {
    int res;
    struct node *last_top;
    if (s->top == NULL) {
        printf("failed to pop! already empty!\n");
        getchar();
        exit(0);
    }
    
    res = s->top->data;
    last_top = s->top;
    s->top = last_top->next;
    free(last_top);
    return res;
}

struct node* peek(struct stack *s) {
    if (s->top == NULL) {
        printf("failed to peek the top! stack already empty!\n");
        getchar();
        exit(0);
    }    
    return s->top;
}

struct node* max(struct stack *s) {
    if (s->top == NULL) {
        printf("failed to find max node! stack already empty!\n");
        getchar();
        exit(0);
    }
    return s->top->max;
}

int main() {
    
    int array[] = {1, 2, 20, 5, 7, 6};
    int size = sizeof(array)/sizeof(array[0]);
    int i;
    /* create a stack */
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->top = NULL;
    
    printf("Pushing...:\n");
    for (i = 0; i < size; ++i) {
        printf("PUSH: %d\n", array[i]);
        push(s, array[i]);
        printf("MAX:  %d\n", max(s)->data);
    }
    printf("Poping...:\n");
    for (i = 0; i < size; ++i) {
        printf("MAX:  %d\n", max(s)->data);
        printf("POP:  %d\n", pop(s));
    }
    return 0;
}

