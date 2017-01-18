/*
    Given: Binary tree and a target Sum
    Expected Result: All paths where sum of nodes along path is equal to target sum
    Assumption: Path starts at Root and ends at Leaf
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* createNode(int val) {
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("failed to allocate!\n");
        getchar();
        exit(0);
    }
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int hasPathSum(node *root, int sum) {
    if (sum == 0) {
        return 1;
    }
    else if (root == NULL) {
        return 0;
    }
    else {
        return hasPathSum(root->left, sum - root->data) ||
               hasPathSum(root->right, sum - root->data);
    }
}


int main() {
    int sum = 21;
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
    struct node *root = createNode(10);
    root->left        = createNode(8);
    root->right       = createNode(2);
    root->left->left  = createNode(3);
    root->left->right = createNode(5);
    root->right->left = createNode(2);
 
    if(hasPathSum(root, sum))
        printf("There is a root-to-leaf path with sum %d", sum);
    else
        printf("There is no root-to-leaf path with sum %d", sum);
 
    getchar();
    return 0;
}