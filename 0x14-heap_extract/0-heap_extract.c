#include "binary_trees.h"

/**
 * heapify - fix the max heap
 * @root: head of the heap tree
 * Return: Nothing
 */
static void heapify(binary_tree_t *root)
{
	binary_tree_t *child = NULL;
	int tem_num = 0;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			child = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				child = root->left;
			else
				child = root->right;
		}

		if (root->n >= child->n)
			break;
		tem_num = root->n;
		root->n = child->n;
		child->n = tem_num;
		root = child;
	}
}

/**
 * get_size - get the number of nodes of heap tree
 * @root: head of the heap tree
 * Return: all the nodes in heap tree
 */
static int get_size(heap_t *root)
{
	return (root ? 1 + get_size(root->left) + get_size(root->right) : 0);
}

/**
 * get_last_node - get the last node in heap_min
 * @root: head of the heap tree
 * Return: last node in heap_min
 */
binary_tree_t *get_last_node(heap_t *root)
{
	int nodes = 0, size_heap = 0;
	binary_tree_t *last_node = NULL;

	size_heap = get_size(root);

	for (nodes = 1; nodes <= size_heap; nodes <<= 1)
		;
	nodes >>= 2;

	for (last_node = root; nodes > 0; nodes >>= 1)
	{
		if (size_heap & nodes)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	return (last_node);
}

/**
 * heap_extract - extract the head heap_min
 * @root: head of the heap tree
 * Return: extracted number
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *last_node = NULL, *head_node = NULL;
	int extracted_num = 0;

	if (!root || !*root)
		return (0);
	head_node = *root;
	if (!head_node->left && !head_node->right)
	{
		extracted_num = head_node->n;
		free(head_node);
		*root = NULL;
		return (extracted_num);
	}

	head_node = *root;
	extracted_num = head_node->n;

	last_node = get_last_node(*root);

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	last_node->left = head_node->left;
	last_node->right = head_node->right;
	last_node->parent = head_node->parent;

	if (head_node->left)
		head_node->left->parent = last_node;
	if (head_node->right)
		head_node->right->parent = last_node;

	*root = last_node;
	free(head_node);

	heapify(*root);

	return (extracted_num);
}
