#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Function to create new levelorder_queue_t node.
 * @node: binary tree node for new node to contain.
 *
 * Return: If error occurs then, NULL.
 *         else, ptr to new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *another;

	another = malloc(sizeof(levelorder_queue_t));
	if (another == NULL)
		return (NULL);

	another->node = node;
	another->next = NULL;

	return (another);
}

/**
 * free_queue - Function to free a levelorder_queue_t queue.
 * @head: ptr to head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tempe;

	while (head != NULL)
	{
		tempe = head->next;
		free(head);
		head = tempe;
	}
}

/**
 * pint_push - Function to run a function on a given binary tree node and
 *             push children into a levelorder_queue_t queue.
 * @node: binary tree node to print and push.
 * @head: double ptr to head of the queue.
 * @tail: double ptr to tail of the queue.
 * @func: ptr to function to call on @node.
 *
 * Description: If malloc fails, exit with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *another;

	func(node->n);
	if (node->left != NULL)
	{
		another = create_node(node->left);
		if (another == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = another;
		*tail = another;
	}
	if (node->right != NULL)
	{
		another = create_node(node->right);
		if (another == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = another;
		*tail = another;
	}
}

/**
 * pop - Function to pop head of a levelorder_queue_t queue.
 * @head: double ptr to head of queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tempe;

	tempe = (*head)->next;
	free(*head);
	*head = tempe;
}

/**
 * binary_tree_levelorder - Function to traverse a binary tree using
 *                          level-order traversal.
 * @tree: ptr to root node of tree to traverse.
 * @func: ptr to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
