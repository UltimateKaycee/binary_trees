#include "binary_trees.h"

/**
 * array_to_avl - Function to build an AVL tree from array.
 * @array: ptr to first element of array to be converted.
 * @size: num of elements in array.
 *
 * Return: ptr to root node of created AVL, or NULL if failed.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t high, low;

	if (array == NULL)
		return (NULL);

	for (high = 0; high < size; high++)
	{
		for (low = 0; low < high; low++)
		{
			if (array[low] == array[high])
				break;
		}
		if (low == high)
		{
			if (avl_insert(&tree, array[high]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
