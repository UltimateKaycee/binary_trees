#include "binary_trees.h"

/**
 * binary_tree_insert_right - Function to insert node as right-child
 *                            of another in binary tree.
 * @parent: ptr to node to insert right-child in.
 * @value: value to store in new node.
 *
 * Return: If parent is NULL or error - NULL.
 *         Otherwise - ptr to new node.
 *
 * Description: If parent has a right-child, new node
 *              takes its place and old right-child is set as
 *              right-child of new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *another;

	if (parent == NULL)
		return (NULL);

	another = binary_tree_node(parent, value);
	if (another == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		another->right = parent->right;
		parent->right->parent = another;
	}
	parent->right = another;

	return (another);
}
