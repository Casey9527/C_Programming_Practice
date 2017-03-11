
// 11:39 - 11:46
void mirror_inplace(tNode *root)
{
	if (root == NULL) {
		return;
	}

	mirror_inplace(root->left);
	mirror_inplace(root->right);

	tNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

tNode* mirror_outplace(tNode *root)
{
	if (root == NULL) {
		return NULL;
	}

	tNode* new_root = createNode(root->val);
	new_root->left  = mirror_outplace(root->right);
	new_root->right = mirror_outplace(root->left);
	return new_root;
}
