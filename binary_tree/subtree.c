
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* newNode (int val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data  = val;
    new_node->left  = NULL;
    new_node->right = NULL;
    return (new_node);    
}

bool areIdentical(node *root1, node *root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

bool isSubtree(node *T, node *S) {
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;
    if (areIdentical(T, S))
        return true;
    return isSubtree(T->left, S) ||
           isSubtree(T->right, S);
}

int main()
{
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    node *T               = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    node *S           = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");
 
    getchar();
    return 0;
}