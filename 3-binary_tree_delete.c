#include "binary_trees.h"

/**
 * binary_tree_delete - Function to deletes binary tree.
 * @tree: ptr to root node of tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
