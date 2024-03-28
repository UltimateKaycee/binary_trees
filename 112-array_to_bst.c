#include "binary_trees.h"

/**
 * array_to_bst - Function to build a bst from an array.
 * @array: ptr to first element of array to be converted.
 * @size: num of elements in @array.
 *
 * Return: ptr to root node of the BST, or NULL if failed.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t right, down;

	if (array == NULL)
		return (NULL);

	for (right = 0; right < size; right++)
	{
		for (down = 0; down < right; down++)
		{
			if (array[down] == array[right])
				break;
		}
		if (down == right)
		{
			if (bst_insert(&tree, array[right]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
