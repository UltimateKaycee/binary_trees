#include "binary_trees.h"

/**
 * binary_tree_insert_left - Function to insers node as left-child of
 *                           of another in binary tree.
 * @parent: ptr to node to insert left-child.
 * @value: value to store in new node.
 *
 * Return: If parent is NULL or error - NULL.
 *         Otherwise - ptr to new node.
 *
 * Description: If parent has a left-child, new node
 *              takes its place and old left-child is set as
 *              left-child of new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *another;

	if (parent == NULL)
		return (NULL);

	another = binary_tree_node(parent, value);
	if (another == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		another->left = parent->left;
		parent->left->parent = another;
	}
	parent->left = another;

	return (another);
}
