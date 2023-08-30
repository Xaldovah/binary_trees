#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t index = 0, size = 0;
	binary_tree_t **queue = NULL, *current = NULL;

	if (tree == NULL)
	{
		return (0);
	}
	size = binary_tree_size(tree);
	queue = calloc(size, sizeof(binary_tree_t *));

	if (queue == NULL)
	{
		return (0);
	}
	queue[index++] = (binary_tree_t *)tree;

	while (index < size)
	{
		current = queue[index];
		index++;

		if (current != NULL)
		{
			queue[index++] = current->left;
			queue[index++] = current->right;
		}
	}
	index--;
	for (; index > 0 && queue[index] == NULL; index--)
		;

	free(queue);

	return (index == 0);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Size of the tree, or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
