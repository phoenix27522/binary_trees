#include "binary_trees.h"

/**
 * binary_tree_node - creates binary tree
 * @parent: root of the binarry tree
 * @value: value of the nodes
 *
 * Return: binary tree
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *left_tree;

	if (parent == NULL)
		return (NULL);

	binary_tree_t *left_tree = binary_tree_node(parent, value);

    if (left_tree == NULL)
        return (NULL);
    
    if (left_tree->left != NULL)
    {
        left_tree->left = parent->left;
        parent->left->parent = left_tree;
    }
    parent->left = left_tree;
    
	return (left_tree);

}

