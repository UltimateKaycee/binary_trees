#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - Function to go through binary tree
 * @tree: ptr to root
 * Return: 1 if all nodes are max and 0 otherwise
 **/
int check_max(const binary_tree_t *tree)
{
	int tempe1 = 1, tempe2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tempe1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tempe2 = check_max(tree->right);
	}
	return (tempe1 && tempe2);
}
/**
 * binary_tree_is_heap - Function to check if bst is heap
 * @tree: ptr to node
 * Return: 1 if BTS or 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tempe;

	if (!tree)
		return (0);

	tempe = binary_tree_is_complete(tree);
	if (!tempe)
		return (0);
	return (check_max(tree));
}
