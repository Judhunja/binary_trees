#include "binary_trees.h"
/**
 * binary_tree_h - calculates the height of a binary tree
 * @tree: pointer to the root node of the binary tree
 * Return: height of the tree
 */
int binary_tree_h(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = (tree->left != NULL) ? binary_tree_h(tree->left) : 0;
	right = (tree->right != NULL) ? binary_tree_h(tree->right) : 0;

	return ((left > right) ? left + 1 : right + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = tree->left ? binary_tree_h(tree->left) : 0;
	right = tree->right ? binary_tree_h(tree->right) : 0;

	return (left - right);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->right == NULL)
		return (1);

	if (binary_tree_h(tree->left) == binary_tree_h(tree->right))
	{
		if (binary_tree_balance(tree->left) == 0 &&
				binary_tree_balance(tree->right) == 0)
			return (1);
	}
	return (0);
}
