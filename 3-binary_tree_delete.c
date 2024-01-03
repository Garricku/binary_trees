#include "binary_trees.h"

/**
 * free_leaf - frees the memory in a leaf of a binary tree struct
 * @node: the node to be freed
 *
 * Return: void/nothing
 */
void free_leaf(binary_tree_t *node)
{
	free(node->left);
	free(node->right);
	free(node->parent);
}

/**
 * to_left_leaf - travels the binary tree to the leftmost leaf
 * @tree: the pointer to the tree to be traveled
 *
 * Return: the leftmost leaf node
 */
binary_tree_t *to_left_leaf(binary_tree_t *tree)
{
	binary_tree_t *left_leaf = tree;

	while (left_leaf->left != NULL)
		left_leaf = left_leaf->left;
	return (left_leaf);
}

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: a pointer to the root node of the tree to delete
 *
 * Return: void/nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left_leaf = tree, *parent = tree, *leaf;

	/* If tree is NULL, do nothing */
	if (tree == NULL)
		return;

	while (tree->right != NULL && tree->left != NULL)
	{
		if (parent->left != NULL)
		{
			left_leaf = to_left_leaf(parent->right);
			parent = left_leaf->parent;
			free_leaf(left_leaf);
		}
		if (parent->right != NULL)
			parent = parent->right;
		if (parent->right == NULL && parent->left == NULL)
		{
			leaf = parent;
			if (parent->parent == NULL)
			{
				free_leaf(leaf);
				continue;
			}
			parent = parent->parent;
			free_leaf(leaf);
		}
	}
	free(tree);
}
