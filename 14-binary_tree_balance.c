#include "binary_trees.h"

/**
 * binary_tree_balance - Function to measure balance factor of a binary tree.
 * @tree: ptr to root node of the to measure the balance factor.
 *
 * Return: If tree is NULL - 0, else balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Function to measure height of a binary tree.
 * @tree: ptr to root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0, else height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t heel = 0, beer = 0;

		heel = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		beer = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((heel > beer) ? heel : beer);
	}
	return (0);
}
