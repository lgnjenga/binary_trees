#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Description: This function creates a new node with the given value
 * and inserts it as the right child of the provided parent node. If the
 * parent already has a right child, the new node takes its place and the
 * old right child becomes the right child of the new node.
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if the parent node is NULL */
	if (parent == NULL)
		return (NULL);

	/* Create a new node and allocate memory for it */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* If the parent already has a right child */
	if (parent->right != NULL)
	{
		/* Set the new node's right child to the current right child of the parent */
		new_node->right = parent->right;
		/* Set the parent of the current right child to the new node */
		new_node->right->parent = new_node;
	}

	/* Set the new node as the right child of the parent */
	parent->right = new_node;

	/* Return a pointer to the created node */
	return (new_node);
}
