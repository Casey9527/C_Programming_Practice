
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a < b ? b : a)

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node* newNode(int data) {
  node* new_node = (node *) malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
 
  return(new_node);
}

// DFS
int getHeight(node *root) {
    if (!root) {
        return 0;   
    }    
    return MAX(getHeight(root->left), getHeight(root->right)) + 1;
}

int main()
{
    struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
   
    printf("Hight of tree is %d", getHeight(root));
   
    getchar();
    return 0;
}

