#include "binary_trees.h"

/**
 * binary_tree_uncle - Function to find uncle of a node
 *                     in binary tree.
 * @node: ptr to node to find uncle of.
 *
 * Return: If node is NULL or has no uncle then, NULL.
 *         else, a ptr to uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
