#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
	{
		return (0);
	}
	size = binary_tree_size(tree);
	return (measure_complete(tree, 0, size));
}

/**
 * measure_complete - Measures if a binary tree is complete
 * @tree: Pointer to the root node of the tree to measure
 * @index: The index of the node
 * @size: Size of the tree
 * Return: 1 if tree is complete, 0 otherwise
*/
int measure_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (index >= size)
	{
		return (0);
	}
	return (measure_complete(tree->left, 2 * index + 1, size) &&
			measure_complete(tree->right, 2 * index + 2, size));
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
