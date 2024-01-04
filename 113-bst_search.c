#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: A pointer to the node containing an int equal to `value`
 *         NULL if tree is NULL
 *         NULL if no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current = (bst_t *)tree;

	if (!tree)
		return (NULL);
	while (current)
	{
		if (value == current->n)
			return (current);
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
	}
	return (NULL);
}
