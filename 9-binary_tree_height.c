#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the
 * height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);
	return (1 + (l > r ? l : r));
}
