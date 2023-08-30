#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a binary search tree, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bst_checker(tree, INT_MIN, INT_MAX));
}

/**
 * bst_checker - Checks if a binary tree is a binary search tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value
 * @max: Maximum value
 * Return: 1 if tree is a binary search tree, 0 otherwise
*/
int bst_checker(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (tree->n <= min || tree->n >= max)
	{
		return (0);
	}
	return (bst_checker(tree->left, min, tree->n) &&
			bst_checker(tree->right, tree->n, max));
}
