#include "binary_trees.h"

/**
 * binary_tree_node - Function to create a binary tree node.
 * @parent: ptr to parent of node to create.
 * @value: value to put in new node.
 *
 * Return: If error - NULL.
 *         Otherwise - ptr to new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *another;

	another = malloc(sizeof(binary_tree_t));
	if (another == NULL)
		return (NULL);

	another->n = value;
	another->parent = parent;
	another->left = NULL;
	another->right = NULL;

	return (another);
}
