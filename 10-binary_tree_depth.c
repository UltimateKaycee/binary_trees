#include "binary_trees.h"

/**
 * binary_tree_depth - Function to measure depth of a node in a binary tree.
 * @tree: ptr to node to measure the depth.
 *
 * Return: If tree is NULL, returns 0, otherwise the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
