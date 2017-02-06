#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* newNode (int data) {
    node *temp = (node *) malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

void printInorder(node *root) {
    if (root == NULL)   return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

/* traverse in inorder, extract all the data value */
void storeInorder(node *root, int inorder[], int *index_ptr) {
    if (root == NULL)   return;
    storeInorder(root->left, inorder, index_ptr);
    inorder[(*index_ptr)] = root->data;
    (*index_ptr)++;
    storeInorder(root->right, inorder, index_ptr);
}

/* count the number of nodes in this tree */
int countNodes (node *root) {
    if (root == NULL)   return 0;
    return countNodes(root->left) + 
           countNodes(root->right) + 1;
}

/* traverse in Inorder again, fill correct value */
void changeBSTNodeValue(int arr[], node *root, int *index_ptr) {
    if (root == NULL)   return;
    changeBSTNodeValue(arr, root->left, index_ptr);
    root->data = arr[(*index_ptr)];
    (*index_ptr)++;
    changeBSTNodeValue(arr, root->right, index_ptr);
}

int compare (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void bt2bst (node *root) {
    if (root == NULL)   return;
    int n = countNodes(root);
    
    int *arr = (int *) malloc(sizeof(int) * n);
    int i = 0;
    storeInorder(root, arr, &i);
    
    qsort(arr, n, sizeof(arr[0]), compare);
    
    i = 0;
    changeBSTNodeValue(arr, root, &i);
    free(arr);
}

int main() {
    node *root = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 
    // convert Binary Tree to BST
    bt2bst(root);
 
    printf("Following is Inorder Traversal of the converted BST: \n");
    printInorder (root);
    printf("\n");
    return 0;
}