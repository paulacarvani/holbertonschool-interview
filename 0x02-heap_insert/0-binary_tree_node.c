#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 *
 *@parent: pointer to the parent of the node created
 *@value: int value of the node created
 *
 * Return: Pointer to the created node or NULL
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
    {
        new_node = create_new_tree(value);
        return (new_node);
    }

    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * create_new_tree - create a new binary tree with head node
 *
 *@value: int value of new head node
 *
 * Return: pointer to created node or NULL
 */

binary_tree_t *create_new_tree(int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}