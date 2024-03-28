#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Function to create a new levelorder_queue_t node.
 * @node: binary tree node for new node to contain.
 *
 * Return: If error then, NULL.
 *        else, ptr to new node.
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
 * @head: ptr to head of queue.
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
 * push - Function to push a node to back of a levelorder_queue_t queue.
 * @node: binary tree node to print and push.
 * @head: dbl ptr to head of queue.
 * @tail: dbl ptr to tail of queue.
 *
 * Description: If malloc fails, exit with status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *another;

	another = create_node(node);
	if (another == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = another;
	*tail = another;
}

/**
 * pop - Function to pop head of a levelorder_queue_t queue.
 * @head: dbl ptr to head of queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tempe;

	tempe = (*head)->next;
	free(*head);
	*head = tempe;
}

/**
 * binary_tree_is_complete - Function to check if binary tree is complete.
 * @tree: ptr to root node of the tree to traverse.
 *
 * Return: If tree is NULL or incomplete - 0.
 *         else, 1.
 *
 * Description: If malloc fails, exit with status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
