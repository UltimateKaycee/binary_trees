#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Function to check if node is a leaf of a binary tree.
 * @node: ptr to node to check.
 *
 * Return: If node is a leaf, 1, else, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Function to return depth of a node in a binary tree.
 * @tree: ptr to node to measure the depth of.
 *
 * Return: depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Function to return a leaf of a binary tree.
 * @tree: ptr to root node of the tree to find a leaf in.
 *
 * Return: ptr to first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Function to check if a binary tree is
 * perfect recursively.
 * @tree: ptr to root node of the tree to check.
 * @leaf_depth: depth of one leaf in the binary tree.
 * @level: The level of current node.
 *
 * Return: If tree is perfect, 1, else 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Function to check if a binary tree is perfect.
 * @tree: ptr to root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         else, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
