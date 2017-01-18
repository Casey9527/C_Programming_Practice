/*
    convert a bst into sorted double-linked list
    do it in-place, treat left as prev, right as next
*/

#include <stdio.h>
#include <stdlib.h>

/* tree node define */
typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
} Node;

/* allocate a treeNode */
Node* createNode(int val)
{
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("allocate node failed\n");
        exit(0);
    }
    
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* print double-linked list from head to tail */
void printList(Node *head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->right;
    }
    printf("\n");
}

/* print double-linked list from tail to head */
void printList_reverse(Node *head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->left;
    }
    printf("\n");
}

/* print a tree */
void printTree(Node *root)
{
    if (root == NULL)   
        return;
    
    printTree(root->left);
    printf("%d\n", root->val);
    printTree(root->right);
}

/*
 *
 * stack is implemented by linked-list
 * each ListNode contains a treeNode reference
 *
 */
typedef struct ListNode{
    Node *node_ref;         
    struct ListNode *next;
} ListNode;

ListNode* createListNode(Node *node)
{
    ListNode *lnode = (ListNode *) malloc(sizeof(ListNode));
    if (lnode == NULL) {
        printf("allocate ListNode failed\n");
        exit(0);
    }
    
    lnode->node_ref = node;
    lnode->next = NULL;
    return lnode;
}

typedef struct {
    int len;
    int size;
    ListNode *top;
} Stack;

Stack* createStack(int n) 
{
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s == NULL) {
        printf("stack allocate failed\n");
        exit(0);
    }
    s->len = 0;
    s->size = n;
    s->top = NULL;
    return s;
}

int isEmpty(Stack *s)
{
    return s->len == 0;
}

int isFull(Stack *s)
{
    return s->len == s->size;
}

void push(Stack *s, Node *node)
{
    if(isFull(s)) {
        printf("stack is full\n");
        return;
    }
    ListNode *lnode = createListNode(node);
    lnode->next = s->top;
    s->top = lnode;
    s->len++;
}

Node* pop(Stack *s)
{
    if(isEmpty(s)) {
        printf("stack is empty\n");
        return NULL;
    }
    s->len--;
    ListNode *old_top = s->top;
    s->top = s->top->next;
    
    old_top->next = NULL;
    return old_top->node_ref;
}

void bst2List(Node *root, Node **head_ref, Node **tail_ref)
{
    if (root == NULL) {
        return;
    }
    
    Stack *s = createStack(20);
    
    Node *cur  = root;
    Node *pre  = NULL;
    
    while (cur || !isEmpty(s)) {
        while (cur) {
            push(s, cur);
            cur = cur->left;
        }
        cur = pop(s);
        if (pre == NULL) {
            *head_ref = cur;
        } else {
            pre->right = cur;
            cur->left = pre;
        }
        pre = cur;
        if (cur->right == NULL && isEmpty(s)) {
            *tail_ref = cur;
            break;
        }
        cur = cur->right;
    }
}

int main(){
    Node *root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(6);
    
    root->left->left = createNode(2);
    root->left->left->left = createNode(1);
    root->left->left->right = createNode(3);
    
    root->right->right = createNode(7);
    root->right->right->right = createNode(8);
    
    printTree(root);
    
    Node *head = NULL;
    Node *tail = NULL;
    bst2List(root, &head, &tail);
    
    printList(head);
    printList_reverse(tail);
    
    return 0;
}