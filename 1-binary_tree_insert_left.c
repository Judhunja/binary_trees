#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to the node to insert the left child
 * @value: value to store in the newnode
 * Return: pointer to newnode, NULL if it failed or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));

	if (newnode == NULL)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	if (!newnode->n)
		return (NULL);

	if (parent->left == NULL)
	{
		parent->left = newnode;
	}
	else
	{
		parent->left->parent = newnode;
		newnode->left = parent->left;
		parent->left = newnode;
	}

	return (newnode);
}
