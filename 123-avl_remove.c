#include "binary_trees.h"

int minValue(avl_t *node)
{
	int minVal = node->n;

	while (node->left != NULL)
	{
		minVal = node->left->n;
		node = node->left;
	}

	return (minVal);
}
/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{	int minVal;

	if (root == NULL)
		return (root);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{	avl_t *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{	temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{	minVal = minValue(root->right);
			root->n = minVal;
			root->right = avl_remove(root->right, minVal);
		}
	}
	if (root == NULL)
		return (root);
	int balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{	root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{	root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
