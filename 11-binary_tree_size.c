#include "binary_trees.h"

/**
 * binary_tree_size - Function to measure size of a binary tree.
 * @tree: ptr to root node of the tree to measure size of.
 *
 * Return: size of tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
