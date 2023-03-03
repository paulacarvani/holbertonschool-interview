#include "list.h"

/**
 * create_list - Creates a node that references itself.
 *
 * @list: List to store the created node.
 * @str: String to input in de created node.
 *
 * Description - This support function is only called if the linked list
 *               passed on add node end (or beginning) is NULL, it will
 *               create a new node that references itself in both "next"
 *               and "prev" directions.
 *
 * Return: -> New node that references itself (List *node) on success.
 *         -> NULL on failure.
 */
List *create_list(List **list, char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	new_node->next = new_node;
	new_node->prev = new_node;
	*list = new_node;
	return (new_node);
}

/**
* add_node_end - Add a new node to the end of a double circular linked list
* @list: the list to modify
* @str: the string to copy into the new node
* Return: Address of the new node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
	List *new_node, *head;

	if (!list || !str)
		return (NULL);

	if (*list == NULL)
	{
		new_node = create_list(list, str);
		return (new_node);
	}
	head = *list;
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = head;
	new_node->prev = head->prev;
	head->prev->next = new_node;
	head->prev = new_node;
	return (new_node);
}
/**
* add_node_begin - Add a new node to the beginning of a
* double circular linked list.
* @list: the list to modify
* @str: the string to copy into the new node
* Return: Address of the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
	List *new_node, *head;


	if (!list || !str)
		return (NULL);

	if (*list == NULL)
	{
		new_node = create_list(list, str);
		return (new_node);
	}
	head = (*list)->prev;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	new_node->prev = head;
	new_node->next = *list;
	(*list)->prev = head->next = new_node;
	*list = new_node;
	return (new_node);
}
