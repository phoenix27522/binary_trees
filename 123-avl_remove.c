#include <stdlib.h>
#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (!temp)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			avl_t *temp = root->right;

			while (temp->left)
				temp = temp->left;
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	if (!root)
		return (NULL);
	return (root);
}

