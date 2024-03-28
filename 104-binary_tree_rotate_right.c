#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function to right-rotate a binary tree.
 * @tree: ptr to root node of the tree to rotate.
 *
 * Return: ptr to new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tempe;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	tempe = pivot->right;
	pivot->right = tree;
	tree->left = tempe;
	if (tempe != NULL)
		tempe->parent = tree;
	tempe = tree->parent;
	tree->parent = pivot;
	pivot->parent = tempe;
	if (tempe != NULL)
	{
		if (tempe->left == tree)
			tempe->left = pivot;
		else
			tempe->right = pivot;
	}

	return (pivot);
}
