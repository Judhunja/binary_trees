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

/**
 * binary_trees_ancestor - finds lowest common ancestor between two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: lowest common ancestor of the two nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_dep, second_dep;

	if (first == NULL || second == NULL || first->parent == NULL ||
			second->parent == NULL)
		return (NULL);

	if (first->parent == second->parent)
		return (first->parent);

	if (second->parent == first->parent)
		return (second->parent);

	first_dep = binary_tree_depth(first);
	second_dep = binary_tree_depth(second);

	while (first_dep > second_dep)
	{
		first = first->parent;
		first_dep--;
	}
	while (second_dep > first_dep)
	{
		second = second->parent;
		second_dep--;
	}

	while (first != second && (first != NULL) && (second != NULL))
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
