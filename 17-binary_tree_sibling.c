#include "binary_trees.h"

/**
 * binary_tree_sibling - Function to find sibling of a
 *                       node in a binary tree.
 * @node: ptr to node to find the sibling of.
 *
 * Return: If node is NULL or there's no sibling then - NULL.
 *         else - a ptr to sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
