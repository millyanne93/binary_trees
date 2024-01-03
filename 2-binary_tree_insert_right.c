#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as a right-child of
 *                           of another node.
 * @parent: parent  of the node.
 * @value: The value.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->rightt = new;
	return (new);
}
