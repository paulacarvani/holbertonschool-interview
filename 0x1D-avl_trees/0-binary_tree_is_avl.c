#include "binary_trees.h"

/**
 * tree_height - Calculates the height of a binary tree.
 *
 * @tree: Tree to calculate height [const binary_tree_t].
 *
 * Return: Height of the binary tree [size_t].
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree == NULL)
		return (0);
	if (tree->right)
		right += tree_height(tree->right) + 1;
	if (tree->left)
		left += tree_height(tree->left) + 1;
	if (left > right)
		return (left);
	return (right);
}

/**
 * avl_tree - Checks if a tree is AVL.
 *
 * @tree: Address of the tree [const binary_tree_t].
 * @max: Max limit [int].
 * @min: Min limit [int].
 *
 * Return: [size_t] number:
 *         -> 1 if tree is AVL.
 *         -> 0 if tree is not AVL.
 *
 */
size_t avl_tree(const binary_tree_t *tree, int max, int min)
{
	/** ls: Left Side | rs: Right Side. */
	size_t ls = tree_height(tree->left), rs = tree_height(tree->right);

	if (tree == NULL)
		return (0);

	if (ls > rs)
		ls = ls - rs;
	else
		ls = rs - ls;
	if (ls > 0)
		return (0);

	ls = 1;
	rs = 1;

	if (tree->left)
	{
		if ((tree->left->n >= tree->n) || (tree->left->n <= min))
			return (0);
		ls = avl_tree(tree->left, tree->n, min);
	}
	if (tree->right)
	{
		if ((tree->right->n <= tree->n) || (tree->right->n >= max))
			return (0);
		rs = avl_tree(tree->right, max, tree->n);
	}
	return (rs == 1 && ls == 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: Pointer to root of a binary tree [const binary_tree_t].
 *
 * Return: [int] number:
 *         -> 1 if tree is AVL.
 *         -> 0 if tree is not AVL.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_tree(tree, INT_MAX, INT_MIN));
}
