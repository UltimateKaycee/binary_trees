#include "binary_trees.h"

/**
 * binary_tree_height - Function to measure height of a binary tree.
 * @tree: ptr to root node of tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, otherwise return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t heel = 0, bero = 0;

		heel = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		bero = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((heel >bero) ? heel : bero);
	}
	return (0);
}
