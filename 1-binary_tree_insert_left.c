#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the left_tree node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the left_tree node.
 *
 * Description: If parent already has a left-child, the left_tree node
 *              takes its place and the old left-child is set as
 *              the left-child of the left_tree node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_tree;

	if (parent == NULL)
		return (NULL);

	left_tree = binary_tree_node(parent, value);
	if (left_tree == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		left_tree->left = parent->left;
		parent->left->parent = left_tree;
	}
	parent->left = left_tree;

	return (left_tree);
}
