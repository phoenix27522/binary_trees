#include "binary_trees.h"
void print_level(const binary_tree_t *tree, int level, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - Traverses a binary tree using lo
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node's value.
 *
 * Description: This function performs level-order traversal on the tree.
 *              It calls the function 'func' for each node's value.
 *              If 'tree' or 'func' is NULL, it does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h, i;

	if (tree == NULL || func == NULL)
		return;

	h = binary_tree_height(tree);
	for (i = 0; i <= h + 1; i++)
		print_level(tree, i, func);
}
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: Height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t r, l;

	if (tree == NULL)
		return (-1);

	r = binary_tree_height(tree->right);
	l = binary_tree_height(tree->left);

	return (1 + (l > r ? l : r));
}

/**
 * print_level - Prints nodes at a given level of the tree.
 * @tree: Pointer to the root node of the tree.
 * @level: Level of the tree to print.
 * @func: Pointer to a function to call for each node's value.
 *
 * Description: This function prints nodes at the given level of the tree
 *              by calling the function 'func'.
 */
void print_level(const binary_tree_t *tree, int level,
		void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}
