#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function to left-rotate a binary tree.
 * @tree: ptr to root node of tree to rotate.
 *
 * Return: ptr to new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tempe;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	tempe = pivot->left;
	pivot->left = tree;
	tree->right = tempe;
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
