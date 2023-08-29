#include "binary_trees.h"

/**
 * max - returns the max of two numbers
 * @a: first number
 * @b: last number
 * Return: 0
 */
size_t max(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to root node of tree to measure height
 * Return: height of the tree or if tree is NULL, 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (max(binary_tree_height(tree->left),
				binary_tree_height(tree->right)));
}
