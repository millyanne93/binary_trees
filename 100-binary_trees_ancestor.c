#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 *         ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor1, *ancestor2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	ancestor1 = first->parent;
	ancestor2 = second->parent;
	if (first == ancestor2 || !ancestor1 || (!ancestor1->parent && ancestor2))
		return (binary_trees_ancestor(first, ancestor2));
	else if (ancestor1 == second || !ancestor2 || (!ancestor2->parent
				&& ancestor1))
		return (binary_trees_ancestor(ancestor1, second));
	return (binary_trees_ancestor(ancestor1, ancestor2));
}
