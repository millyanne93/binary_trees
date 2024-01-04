#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *left_child, *left_right;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	left_child = tree->left;
	left_right = left_child->right;

	left_child->right = tree;
	tree->left = left_right;
	if (left_right != NULL)
		left_right->parent = tree;
	new_root = tree->parent;
	tree->parent = left_child;
	left_child->parent = new_root;
	if (new_root != NULL)
	{
		if (new_root->left == tree)
			new_root->left = left_child;
		else
			new_root->right = left_child;
	}
	return (left_child);
}
