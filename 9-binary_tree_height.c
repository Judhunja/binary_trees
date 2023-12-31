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
	size_t left;
	size_t right;

	if (tree == NULL)
		return (0);

	left = (tree->left != NULL) ? 1 + binary_tree_height(tree->left) : 0;
	right = (tree->right != NULL) ? 1 + binary_tree_height(tree->right) : 0;

	return (max(left, right));
}
