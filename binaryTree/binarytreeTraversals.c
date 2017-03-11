/**
 *
 *	binary tree traversals
 *	- pre-order, in-order, post-order
 *  - iterative, recursive
 *
 **/

void preorder_iterative(tNode* root);
void inorder_iterative(tNode* root);
void postorder_iterative(tNode* root);
void preorder_recursive(tNode *root);
void inorder_recursive(tNode *root);
void postorder_recursive(tNode *root);

void preorder_iterative(tNode* root)
{
	if (!root) return;
	Stack* s = createStack(cap);

	push(s, root);
	tNode* cur = NULL;

	while (!isEmpty(s)) {
		cur = pop(s);
		printf("%d\n", cur->val);
		if (cur->right) {
			push(s, cur->right);
		}
		if (cur->left) {
			push(s, cur->left);
		}
	}

}

void inorder_iterative(tNode* root)
{
	if (!root) return;
	Stack* s = createStack(cap);

	tNode* cur = root;
	while (cur || !isEmpty(s)) {
		while (cur) {
			push(s, cur);
			cur = cur->left;
		}
		cur = pop(s);
		printf("%d\n", cur->val);
		cur = cur->right;
	}
}

void postorder_iterative(tNode* root)
{
	if (!root) return;
	Stack* s = createStack(cap);
	push(s, root);

	tNode* cur, *pre = NULL;

	while (!isEmpty(s)) {
		cur = peek(s);
		if (!pre || pre->left == cur || pre->right == cur) {	// traverse down the tree
			if (cur->left) {
				push(s, cur->left);
			} else if (cur->right){
				push(s, cur->right);
			}
		} else if (cur->left == pre) {	// traverse up the tree from the left
			if (cur->right) {
				push(s, cur->right);
			}
		} else {						// traverse up the tree from the right
			printf('%d\n', peek(s)->val);
			pop(s);
		}
		pre = cur;
	}
}

void preorder_recursive(tNode *root)
{
	if (!root) return;

	printf("%d\n", root->val);
	preorder_recursive(root->left);
	preorder_recursive(root->right);
}

void inorder_recursive(tNode *root)
{
	if (!root) return;
	inorder_recursive(root->left);
	printf("%d\n", root->val);
	inorder_recursive(root->right);
}

void postorder_recursive(tNode *root)
{	
	if (!root) return;
	postorder_recursive(root->left);
	postorder_recursive(root->right);
	printf("%d\n", root->val);
}