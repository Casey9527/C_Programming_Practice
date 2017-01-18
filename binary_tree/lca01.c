/*
 * find the least common ancestor of two nodes. 
 * assume the two nodes are in the tree.
 */

tree_node * lca(tree_node *root, tree_node *n1, tree_node *n2)
{
    if (root == NULL || root = n1 || root == n2)
        return root;
    tree_node *left, *right;
    
    left = lca(root->left, n1, n2);
    right = lca(root->right, n1, n2);
    
    if (!left && !right)
        return NULL;
        
    if (left && !right)
        return left;
    
    if (!left && right)
        return right;
    
    return root;
}
