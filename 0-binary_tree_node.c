#include "binary_trees.h"

/**
 * binary_tree_node - creates a pointer to a binary tree node
 * @parent: pointer to the parent node to create
 * @value: value to insert into the new node
 * Return: a pointer to the new node, or NULL if it failed
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));

	if (newnode == NULL)
		return (NULL);

	newnode->n = value;

	if (!newnode->n)
		return (NULL);

	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);
}
