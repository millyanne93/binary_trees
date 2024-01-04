#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @root: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **root, int value)
{
	bst_t *current = NULL;
	bst_t *parent = NULL;
	bst_t *new_node = NULL;

	if (!root)
		return (NULL);
	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));
	current = *root;

	while (current)
	{
		parent = current;

		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else if (value == current->n)
			return (NULL);
	}
	new_node = binary_tree_node(NULL, value);

	if (parent == NULL)
		parent = new_node;
	else if (value < parent->n)
	{
		parent->left = new_node;
		new_node->parent = parent;
	}
	else
	{
		parent->right = new_node;
		new_node->parent = parent;
	}
	return (new_node);
}
