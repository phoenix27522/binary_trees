#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the right_tree node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the right_tree node.
 *
 * Description: If parent already has a left-child, the right_tree node
 *              takes its place and the old left-child is set as
 *              the left-child of the right_tree node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_tree;

	if (parent == NULL)
		return (NULL);

	right_tree = binary_tree_node(parent, value);
	if (right_tree == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		right_tree->right = parent->right;
		parent->right->parent = right_tree;
	}
	parent->right = right_tree;

	return (right_tree);
}
