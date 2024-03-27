#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Function to check if node is a leaf of binary tree.
 * @node: ptr to node to check.
 *
 * Return: If node is a leaf then - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
