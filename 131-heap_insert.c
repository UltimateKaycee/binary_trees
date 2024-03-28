#include "binary_trees.h"

/**
 * heap_insert - Function to insert value in Max Binary Heap
 * @root: dbl ptr to root node of the Heap to insert the value
 * @value: value to store in node
 *
 * Return: ptr to created node or NULL if failed
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tempe;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	

	another = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = another) : (tree->left = another);

	flip = another;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tempe = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tempe;
		another = another->parent;
	}
	
	return (another);
}

/**
 * binary_tree_size - Function to measure size of a binary tree
 * @tree: tree to measure size of
 *
 * Return: size of tree and
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
