#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */

/* AVL tree insertion function */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	if (!array || size == 0)
		return (NULL);

	avl_t *root = NULL;

	for (i = 0; i < size; i++)
	{
		if (avl_insert(&root, array[i]) == NULL)
			return (NULL);
	}

	return (root);
}

