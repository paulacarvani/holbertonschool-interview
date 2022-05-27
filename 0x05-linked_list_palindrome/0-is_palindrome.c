#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - checks if a linked list of integers is a palindrome
 *
 *@head: head node of the linked list
 *
 * Return: true | false
 */

int is_palindrome(listint_t **head)
{
	int start = 0;
	int end;
	int list[5000];

	end = build_list(list, head);

	if (end == 0)
		return (true);

	for (; start < end; start++, end--)
	{
		if (list[start] != list[end])
		{
			return (false);
		}
	}

	return (true);
}

/**
 * build_list - build an array of integers from a listint_t linked list
 *@list: array of integers to populate
 *@head: head node of the linked list
 */

int build_list(int *list, listint_t **head)
{
	listint_t *temp = *head;
	int index;

	for (index = 0; temp != NULL; index++)
	{
		list[index] = temp->n;
		temp = temp->next;
	}

	return (index - 1);
}
