
/* 
    validate binary search tree
    in-order traversal without using global variable
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
    node *prev = NULL;
    validBSTRecur(root, &prev);
    
}
int validBSTRecur(node *root, node **prev_ref) {
    
    if (root == NULL)
        return 1;
    /* check left child */
    if (!validBSTRecur(root->left, prev_ref))
        return 0;
    /* check root */
    if (*prev_ref && (*prev_ref)->data >= root->data)
        return 0;
    /* update prev */
    *prev_ref = root;
    /* check right child */
    if (!validBSTRecur(root->right, prev_ref))
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