#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Function to measure height of a binary tree.
 * @tree: ptr to root node of tree to measure height.
 *
 * Return: If tree is NULL, return 0, else height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t heel = 0, beer = 0;

		heel = tree->left ? 1 + height(tree->left) : 1;
		beer = tree->right ? 1 + height(tree->right) : 1;
		return ((heel > beer) ? heel : beer);
	}
	return (0);
}

/**
 * is_avl_helper - Function to check if a binary tree is a valid AVL tree.
 * @tree: ptr to root node of tree to check.
 * @lo: value of smallest node visited.
 * @hi: value of largest node visited.
 *
 * Return: If tree is a valid AVL tree then, 1, else 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Function to check if binary tree is valid AVL tree.
 * @tree: ptr to root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
