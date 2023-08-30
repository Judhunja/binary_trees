#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node(edges from the root)
 * @tree: pointer to the node to measure the depth
 * Return: 0 if tree is NULL, otherwise depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dep;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	dep = 0;

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		dep++;
	}
	return (dep);
}
