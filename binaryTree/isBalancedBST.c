/* program to check if a tree is height-balanced or not */
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* newNode(int data) {
    node* new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return(new_node);
}

int isBalanced(node *root, int *height) {
    if (root == NULL) {
        *height = 0;
        return 1;
    }
    /* divide */
    int lh = 0, rh = 0;
    int l = 0, r = 0;
    l = isBalanced(root->left, &lh);
    r = isBalanced(root->right, &rh);
    
    *height = (lh > rh ? lh : rh) + 1;
    
    if ((lh - rh >= 2) || (rh - lh) >= 2)
        return 0;
    /* conquer */
    else return l&&r;
}


int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  node *root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
  root->left->left->left->left = newNode(8);
 
  if(isBalanced(root, &height))
    printf("Tree is balanced");
  else
    printf("Tree is not balanced");    
 
  getchar();
  return 0;
}
