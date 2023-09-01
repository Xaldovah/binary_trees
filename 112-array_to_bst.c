#include "binary_trees.h"

/**
 * array_to_bst - Creates a binary search tree from an array
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 * Return: Pointer to the root node of the tree, or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL, *node;
	size_t i;

	for (i = 0; i < size; i++)
	{
		node = bst_insert(&root, array[i]);
		if (node == NULL)
		{
			return (NULL);
		}
	}
	return (root);
}


/**
 * bst_node - Creates a binary search tree node
 * @parent: Pointer to the parent node of the new node
 * @value: Value to insert
 * Return: Pointer to the new node
*/
bst_t *bst_node(bst_t *parent, int value)
{
	bst_t *new_node;

	new_node = malloc(sizeof(bst_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
