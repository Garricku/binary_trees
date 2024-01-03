#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: A pointer to the node to find the uncle
 *
 * Return: A pointer to the uncle node
 * If node is NULL, return NULL
 * If node has no uncle, return NUL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = node, *parent = node;

	if (node == NULL || node->parent->parent == NULL
			|| node->parent == NULL)
		return (NULL);

	parent = node->parent->parent->right;
	if (node->parent != parent)
		return (parent);
	else
		return (uncle = node->parent->parent->left);

	return (NULL);
}
