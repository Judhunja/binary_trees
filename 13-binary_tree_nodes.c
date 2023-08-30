#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with atleast 1 child
 * @tree: pointer to root node of the tree to count number of nodes
 * Return: 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
