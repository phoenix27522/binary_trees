#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *current, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	current = tree->right;
	tmp = current->left;
	current->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = current;
	current->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = current;
		else
			tmp->right = current;
	}

	return (current);
}
