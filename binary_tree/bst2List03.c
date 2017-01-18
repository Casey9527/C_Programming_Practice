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

void bst2List(Node *root, Node **prev, Node **head_ref)
{
    if (root == NULL) {
        return;
    }
    
    bst2List(root->left, prev, head_ref);
    
    if (*prev == NULL) {
        *head_ref = root;
    } else {
        (*prev)->right = root;
        root->left  = *prev;
    }
    *prev = root;
    bst2List(root->right, prev, head_ref);
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

    Node *prev = NULL;
    Node *head = NULL;
    Node *tail = NULL;
    
    bst2List(root, &prev, &head);
    
    tail = prev;
    
    printList(head);
    printList_reverse(tail);
    
    return 0;
}