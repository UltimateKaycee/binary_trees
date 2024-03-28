#include "binary_trees.h"

/**
 * bst_insert - Function to inserts a value in a BST.
 * @tree: dbl ptr to root node of BST to insert the value.
 * @value: value to store in node to be inserted.
 *
 * Return: ptr to created node, or NULL if fails.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *another;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			another = binary_tree_node(curr, value);
			if (another == NULL)
				return (NULL);
			return (*tree = another);
		}

		if (value < curr->n)
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			another = binary_tree_node(curr, value);
			if (another == NULL)
				return (NULL);
			return (curr->left = another);
		}
		if (value > curr->n)
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			another = binary_tree_node(curr, value);
			if (another == NULL)
				return (NULL);
			return (curr->right = another);
		}
	}
	return (NULL);
}
