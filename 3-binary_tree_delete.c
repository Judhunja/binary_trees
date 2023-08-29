#include "binary_trees.h"

/**
 * binary_tree_delete - deletes entire binary tree or if the tree is NULL,
 * does nothing
 * @tree: pointer to the root node of the tree to delete
 * Return: nothing
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *del;

	del = tree;

	if (tree == NULL)
		return;

	if (tree->left != NULL)
	{
		del = tree->left;
		free(tree);
		tree = del;
	}

	if (tree->right != NULL)
	{
		del = tree->right;
		free(tree);
		tree = del;
	}
	free(tree);
}
