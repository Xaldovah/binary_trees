#include "binary_trees.h"

/**
 * array_to_bst - Creates a binary search tree from an array
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 * Return: Pointer to the root node of the tree, or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			binary_tree_delete(root);
			return (NULL);
		}
	}
	return (root);
}

/**
 * binary_tree_delete - Deletes a binary tree
 * @tree: Pointer to the root node of the tree to delete
 * Return: Nothing
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
