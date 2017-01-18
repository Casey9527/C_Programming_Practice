/*  traverse a binary tree in preorder way
    iterativetly
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE (50)

typedef struct tNode {
    int data;
    struct tNode *left;
    struct tNode *right;
} tNode;

tNode* newtNode(int val) {
    tNode* node = (tNode *) malloc(sizeof(tNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
/* implement stack using array */
typedef struct stack {
    int count;
    int capacity;
    struct tNode** tNodes;
} stack;

stack* newStack(int size) {
    stack *s = (stack *) malloc(sizeof(stack));
    s->capacity = size;
    s->count = -1;
    s->tNodes = (tNode **)malloc(sizeof(tNode *)*size);
    return s;
}

void push(stack *s, tNode *node) {
    if(isFull(s)) {
        printf("push failed. stack already full\n");
        return;
    }
    s->tNodes[++(s->count)] = node;
}

void pop(stack *s) {
    if(isEmpty(s)) {
        printf("pop failed. stack already empty\n");
        return;
    }
    tNode *last_top = s->tNodes[(s->count)--];
    free(last_top);
}

tNode* peek(stack *s) {
    if(isEmpty(s)) {
        printf("peek failed. stack already empty\n");
        return NULL;
    }
    return s->tNodes[s->count];
}

int isEmpty(stack *s) {
    return s->count == -1;
}

int isFull(stack *s) {
    return s->count == s->capacity - 1;    
}

void preorderBST_iter(tNode *root) {
    if (root == NULL)   return;
    stack *s = newStack(MAX_STACK_SIZE);
    tNode *curr;
    push(s, root);
    while (!isEmpty(s)) {
        curr = peek(s);
        printf("%d ", curr->data);
        pop(s);
        if (curr->right)
            push(s, curr->right);
        if (curr->left)
            push(s, curr->left);
    }
    printf("\n");
}

void printTree(tNode *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    tNode *root = newtNode(1);
    root->left  = newtNode(2);
    root->right = newtNode(3);
    root->left->left  = newtNode(4);
    root->left->right = newtNode(5);
    
    root->right->left = newtNode(6);
    root->right->right = newtNode(7);
    printTree(root);
    printf("\n");
    preorderBST_iter(root);
    return 0;
}



