
/* 
    validate binary search tree
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node node;

node* newNode(int data) {
  node* new_node = (node *) malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
 
  return(new_node);
}


int validBST(node *root) {
    static node *prev = NULL;
    
    if (root == NULL)
        return 1;
    /* check left child */
    if (!validBST(root->left))
        return 0;
    /* check root */
    if (prev && prev->data >= root->data)
        return 0;
    /* update prev */
    prev = root;
    /* check right child */
    if (!validBST(root->right))
        return 0;
    
    return 1;
}


int main()
{
  node *root        = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
 
  if(validBST(root))
    printf("Is BST\n");
  else
    printf("Not a BST\n");
     
  getchar();
  return 0;
}  