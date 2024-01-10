#include "binary_trees.h"

/**
 * findMinInRightSubtree - Finds the minimum value in the
 * right subtree of a node.
 * @node: The node to check.
 * Return: The minimum value found in the right subtree.
 */
int findMinInRightSubtree(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = findMinInRightSubtree(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * replaceWithSuccessor - Replaces a node's value with the minimum
 * value in its right subtree.
 * @root: The node to update.
 * Return: The new value found.
 */
int replaceWithSuccessor(bst_t *root)
{
	int new_value = 0;

	new_value = findMinInRightSubtree(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 * removeNodeFromBST - Removes a node from a BST based on its children.
 * @root: The node to remove.
 * Return: 0 if the node has no children or rearranges the
 * tree based on the number of children.
 */
int removeNodeFromBST(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (replaceWithSuccessor(root));
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: The root of the tree.
 * @value: The value of the node to remove.
 * Return: The updated tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = removeNodeFromBST(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
