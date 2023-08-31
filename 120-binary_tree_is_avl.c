#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a tree is AVL
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is AVL, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, is_left_avl, is_right_avl;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (abs(left_height - right_height) > 1)
	{
		return (0);
	}
	is_left_avl = binary_tree_is_avl(tree->left);
	if (!is_left_avl)
	{
		return (0);
	}
	is_right_avl = binary_tree_is_avl(tree->right);
	if (!is_right_avl)
	{
		return (0);
	}
	return (1);
}

/**
 * binary_tree_measure - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height of the tree, or 0 if tree is NULL
*/
size_t binary_tree_measure(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	left_height = binary_tree_measure(tree->left) + 1;
	right_height = binary_tree_measure(tree->right) + 1;

	if (left_height > right_height)
	{
		return (left_height);
	}
	else
	{
		return (right_height);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	return (binary_tree_measure(tree));
}
