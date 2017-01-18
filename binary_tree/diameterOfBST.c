/*
    diameter of binary tree:
        number of nodes on the longest path between any two nodes in the tree
*/

#define MAX(a, b) \
       ({ __typeof__ (a) _a = (a); \
          __typeof__ (b) _b = (b); \
          _a > _b ? _a : _b;})


#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
    int data;
    struct tNode *left, *right;
} tNode;

tNode* newNode(int data)
{
    tNode* node = (tNode *) malloc(sizeof(tNode));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int diameterOfBST(tNode *root, int *height)
{
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    
    int lh, rh, ldiameter, rdiameter;
    lh = rh = 0;
    
    ldiameter = diameterOfBST(root->left,  &lh);
    rdiameter = diameterOfBST(root->right, &rh);
    
    *height = MAX(lh, rh) + 1;
    
    return MAX((lh + rh + 1), MAX(ldiameter, rdiameter));
}

int main()
{
    /* Constructed binary tree is 
                1
              /   \
            2      3
          /  \
        4     5
    */
    tNode *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    
    int height = 0;
    
    printf("Diameter of the given binary tree is %d\n", 
            diameterOfBST(root, &height));
    return 0;
}

