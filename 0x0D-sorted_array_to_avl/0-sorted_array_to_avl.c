#include "binary_trees.h"

/**
 * insert_node - Ceates a node.
 * @parent: Points to the previous node.
 * @n: Value to be inserted inside node
 *
 * Return: The new node or null if it fails.
 */
binary_tree_t *insert_node(binary_tree_t *parent, int n)
{
	binary_tree_t *node = NULL;

	node = malloc(sizeof(binary_tree_t));

	if (!node)
	{
		return (NULL);
	}

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = n;

	return (node);
}

/**
 * insert - Auxiliary Function for sort insertion
 * @array: Points to element to be converted
 * @min: lower limit
 * @max: upper limit
 *
 * Return: Pointer to node of AVL tree, null if it fails.
 */
avl_t *insert(int *array, int min, int max)
{
	int middle;
	avl_t *tree;

	if (min > max)
	{
		return (NULL);
	}

	middle = (max + min) / 2;

	tree = insert_node(NULL, array[middle]);

	if (!tree)
	{
		return (NULL);
	}

	tree->left = insert(array, min, middle - 1);

	tree->right = insert(array, middle + 1, max);

	if (tree->left)
		tree->left->parent = tree;

	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

/**
 * sorted_array_to_avl - takes in array and builds AVL tree
 * @array: points to array to be converted
 * @size: number of values inside array
 *
 * Return: A pointer to the head of the array, null if it fails.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array)
	{
		return (NULL);
	}

	if (size < 1)
	{
		return (NULL);
	}

	root = insert(array, 0, size - 1);

	return (root);
}
