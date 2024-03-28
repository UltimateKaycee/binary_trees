#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Function to measure height of binary tree
 * @tree: ptr to root node of the tree to measure
 *
 * Return: return height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_height(tree->left);

	if (tree->right)
		height_r = 1 + tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}
/**
 * tree_size_h - Function to measure sum of heights of binary tree
 * @tree: ptr to root node of tree to measure
 *
 * Return: return height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_r = 1 + tree_size_h(tree->right);

	return (height_l + height_r);
}

/**
 * _preorder - Function to go through binary tree using pre-order traversal
 * @tree: ptr to root node of tree to go through
 * @node: last node to traverse
 * @height: height of tree
 *
 * Return: None
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - Function to heapify max binary heap
 * @root: ptr to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tempe1, *tempe2;

	if (!root)
		return;

	tempe1 = root;

	while (1)
	{
		if (!tempe1->left)
			break;
		if (!tempe1->right)
			tempe2 = tempe1->left;
		else
		{
			if (tempe1->left->n > tempe1->right->n)
				tempe2 = tempe1->left;
			else
				tempe2 = tempe1->right;
		}
		if (tempe1->n > tempe2->n)
			break;
		value = tempe1->n;
		tempe1->n = tempe2->n;
		tempe2->n = value;
		tempe1 = tempe2;
	}
}

/**
 * heap_extract - Function to extract root node from a Max Binary Heap
 * @root: ptr to heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
