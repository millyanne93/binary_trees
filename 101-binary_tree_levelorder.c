#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: Size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree
 * @tree: the root node of the tree to traverse
 * @func: a function to call for each node
 *
 * Description: The value in each node must be passed as a parameter to func
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t size;
	binary_tree_t **queue;
	size_t first = 0, second = 0;

	if (tree == NULL || func == NULL)
		return;
	size = binary_tree_size(tree);

	if (size == 0)
		return;
	queue = malloc(sizeof(binary_tree_t *) * size);

	if (queue == NULL)
		return;
	queue[second++] = (binary_tree_t *)tree;

	while (first < second)
	{
		binary_tree_t *current = queue[first++];

		func(current->n);
		if (current->left != NULL)
			queue[second++] = current->left;
		if (current->right != NULL)
			queue[second++] = current->right;
	}
	free(queue);
}
