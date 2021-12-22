#include "binary_trees.h"

/**
 * *binary_tree_node - Create a binary tree node
 *
 * @value: Integer stored in the node
 * @parent: Pointer to the parent node
 * Return: Returns new node, or NULL if it fails
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node)
	{
		new_node->parent = parent;
		new_node->right = NULL;
		new_node->left = NULL;
		new_node->n = value;

	}

	return (new_node);
}
