#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Function to check if binary tree is valid binary
 * search tree.
 * @tree: ptr to root node of the tree to check.
 * @lo: value of the smallest node visited.
 * @hi: value of the largest node visited.
 *
 * Return: If tree is valid BST then, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Function to check if binary tree
 * is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid binary search tree, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
