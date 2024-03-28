#include "binary_trees.h"

/**
 * tree_size - Function to measure sum of heights of a binary tree
 * @tree: ptr to root node of tree to measure
 *
 * Return: return height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - Function to convert a Binary Max Heap
 * to a sorted array of int
 *
 * @heap: ptr to root node of the heap to convert
 * @size: address to store size of the array
 *
 * Return: ptr to array in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int high, *ha = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	ha = malloc(sizeof(int) * (*size));

	if (!ha)
		return (NULL);

	for (high = 0; heap; high++)
		ha[high] = heap_extract(&heap);

	return (ha);
}
