// insert a node into a bst

void bstInsertion(Node *root, int key, int val)
{
    if (root == NULL) {
        root = newNode(key, val);
    } else if (key > root->val) {
        bstInsertion(root->right, key, val);
    } else if (key < root->val) {
        bstInsertion(root->left, key, val);
    
}
