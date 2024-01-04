#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - goes through a binary tree in level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void/nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
/*heap_t *queue = NULL;*/

	if (tree == NULL || func == NULL)
		return;
}
