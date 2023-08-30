#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree(number of nodes)
 * @tree: pointer to the root node of tree
 * Return: 0 if tree is NULL, otherwise size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_left, size_right;

	if (tree == NULL)
		return (0);

	size_left = tree->left ? binary_tree_size(tree->left) : 0;
	size_right = tree->right ? binary_tree_size(tree->right) : 0;

	return (size_left + size_right + 1);
}
