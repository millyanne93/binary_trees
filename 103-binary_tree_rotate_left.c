#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *right_child, *right_left;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	right_child = tree->right;
	right_left = right_child->left;

	right_child->left = tree;
	tree->right = right_left;
	if (right_left != NULL)
		right_left->parent = tree;
	new_root = tree->parent;
	tree->parent = right_child;
	right_child->parent = new_root;
	if (new_root != NULL)
	{
		if (new_root->left == tree)
			new_root->left = right_child;
		else
			new_root->right = right_child;
	}
	return (right_child);
}
