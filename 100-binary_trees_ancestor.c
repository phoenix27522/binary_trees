#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node of the two
 *         or NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *index;

	if (first == NULL || second == NULL)
		return (NULL);

	while (first != NULL)
	{
		index = second;
		while (index != NULL)
		{
			if (index == first)
				return ((binary_tree_t *)first);
			index = index->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
