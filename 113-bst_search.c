#include "binary_trees.h"

/**
 * bst_search - Function to search for value in a bst.
 * @tree: ptr to root node of BST to search.
 * @value: value to search for in BST.
 *
 * Return: If the tree is NULL or value isn't found then, NULL.
 *         else, a ptr to node with the value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
