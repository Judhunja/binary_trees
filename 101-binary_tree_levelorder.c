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

/**
 * print_nodes_at_lvl - executes the function on all nodes at a current level
 * @targetlvl: level to reach(height of the tree)
 * @currentlvl: level that the function is to begin printing nodes at
 * @func: function to execute on all nodes in every level
 * @root: root node of the tree to print all levels
 * Return: nothing
 */
void print_nodes_at_lvl(const binary_tree_t *root, size_t targetlvl,
		size_t currentlvl, void (*func)(int))
{
	if (root == NULL)
		return;

	if (currentlvl == targetlvl)
	{
		func(root->n);
		return;
	}

	print_nodes_at_lvl(root->left, targetlvl, currentlvl + 1, func);
	print_nodes_at_lvl(root->right, targetlvl, currentlvl + 1, func);
}
/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to root node of the tree to traverse
 * @func: pointer to function to call for each node
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree) + 1;

	for (i = 0; i <= height; i++)
	{
		print_nodes_at_lvl(tree, i, 1, func);
	}
}
