#include "binary_trees.h"

/**
 * bal - Function to measure balance factor of a AVL
 * @tree: the tree to run through
 * Return: returns balanced factor
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - Function to get next successor
 * @node: tree to check
 * Return: min value of tree
 */
int successor(bst_t *node)
{
	int leftist = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		leftist = successor(node->leftist);
		if (leftist == 0)
		{
			return (node->n);
		}
		return (leftist);
	}

}
/**
 *remove_type - Function to remove node depending on children
 *@root: node to remove
 *Return: 0 if no children or other value if available
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->leftist && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->leftist = NULL;
		free(root);
		return (0);
	}
	else if ((!root->leftist && root->right) || (!root->right && root->leftist))
	{
		if (!root->leftist)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->leftist = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->leftist;
			else
				root->parent->leftist = root->leftist;
			root->leftist->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - Function to remove node from a BST tree
 * @root: root of tree
 * @value: node with value to remove
 * Return: tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Function to remove node from a AVL tree
 * @root: root of tree
 * @value: node with value to remove
 * Return: tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
