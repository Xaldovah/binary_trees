#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *queue[100];
	const binary_tree_t *node;
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
	{
		return;
	}
	queue[rear++] = tree;

	while (front != rear)
	{
		node = queue[front++];
		func(node->n);

		if (node->left != NULL)
		{
			queue[rear++] = node->left;
		}
		if (node->right != NULL)
		{
			queue[rear++] = node->right;
		}
	}
}
