#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node, or NULL on failure, if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* if parent is NULL, return NULL */
	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	/* if malloc fails return NULL */
	if (new_node == NULL)
		return (NULL);

	/**
	 * if parent already has a right-child, the new node must take it's
	 * place, and the old right-child must be set as the right-child of the
	 * new node, otherwise the default value is NULL
	 */
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	else
		new_node->right = NULL;
	/* assign the rest of the values */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	parent->right = new_node;

	/* return the pointer to the new node */
	return (new_node);
}
