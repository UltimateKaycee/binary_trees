#include "binary_trees.h"

/**
 * binary_tree_preorder - Function to go through binary
 * tree with pre-order traversal.
 * @tree: ptr to root node of tree to traverse.
 * @func: ptr to function to call for each of the nodes.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
