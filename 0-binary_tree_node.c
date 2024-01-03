#include "binary_trees.h"

/**
 * binary_tree_node - creates binary tree
 * @parent: root of the binarry tree
 * @value: value of the nodes
 *
 * Return: binary tree
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = malloc(sizeof(binary_tree_t));

	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = value;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = parent;
	return (newnode);

}
