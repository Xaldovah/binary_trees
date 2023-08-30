#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
	{
		return;
	}
	queue_push(&queue, (void *)tree);

	while (queue)
	{
		current = (binary_tree_t *)queue_pop(&queue);

		if (current)
		{
			func(current->n);

			if (current->left)
			{
				queue_push(&queue, (void *)current->left);
			}
			if (current->right)
			{
				queue_push(&queue, (void *)current->right);
			}
		}
	}
}

/**
 * queue_push - Adds an element to the queue
 * @queue: Pointer to the queue
 * @data: Pointer to the data
 * Return: Nothing
*/
void queue_push(queue_t **queue, void *data)
{
	QueueNode *new_node = NULL;

	if (queue == NULL || *queue == NULL || data == NULL)
	{
		return;
	}
	new_node = malloc(sizeof(QueueNode));

	if (new_node == NULL)
	{
		return;
	}
	new_node->data = data;
	new_node->next = NULL;

	if ((*queue)->rear == NULL)
	{
		(*queue)->front = new_node;
		(*queue)->rear = new_node;
	}
	else
	{
		(*queue)->rear->next = new_node;
		(*queue)->rear = new_node;
	}
}

/**
 * queue_pop - Removes an element from the queue
 * @queue: Pointer to the queue
 * Return: Pointer to the data
*/
void *queue_pop(queue_t **queue)
{
	QueueNode *front_node;
	void *data;

	if (queue == NULL || *queue == NULL || (*queue)->front == NULL)
	{
		return (NULL);
	}
	front_node = (*queue)->front;
	data = front_node->data;

	(*queue)->front = front_node->next;
	if ((*queue)->front == NULL)
	{
		(*queue)->rear = NULL;
	}
	free(front_node);
	return (data);
}
