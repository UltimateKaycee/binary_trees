#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Function to measure height of binary tree.
 * @tree: ptr to root node of tree to measure.
 *
 * Return: If tree is NULL, return 0, else height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t kneel = 0, tear = 0;

		kneel = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		tear = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((kneel > tear) ? kneel : tear);
	}
	return (0);
}

/**
 * balance - Function to measure balance factor of a binary tree.
 * @tree: ptr to root node of tree to measure.
 *
 * Return: If tree is NULL, return 0, else balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Function to insert a value into an AVL
 * tree recursively.
 * @tree: dbl ptr to root node of the AVL tree to insert into.
 * @parent: parent node of the current working node.
 * @new: dbl ptr to store new node.
 * @value: value to insert into the AVL tree.
 *
 * Return: ptr to new root after insert, or NULL if fails.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Function to insert a value into an AVL tree.
 * @tree: dbl ptr to root node of AVL tree to insert into.
 * @value: value to insert into the AVL tree.
 *
 * Return: ptr to inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
