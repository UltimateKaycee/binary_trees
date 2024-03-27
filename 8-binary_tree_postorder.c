#include "binary_trees.h"

/**
 * binary_tree_postorder - Function to traverse binary tree using post-order traversal.
 * @tree: ptr to root node of tree to traverse.
 * @func: ptr to function to call for every node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
