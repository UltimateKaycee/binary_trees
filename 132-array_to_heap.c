#include "binary_trees.h"

/**
 * array_to_heap - Function to build a Max Binary Heap tree from array
 * @array: ptr to first element of array
 * @size: num of element in array
 *
 * Return: ptr to root node of created Binary Heap and
 *         NULL upon fail
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int high;
	heap_t *root = NULL;

	for (high = 0; high < size; high++)
		heap_insert(&root, array[high]);

	return (root);
}
