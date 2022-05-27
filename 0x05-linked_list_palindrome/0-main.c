#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

#define TEST_LENGTH 10

void build_test_list(listint_t **head, int *test);

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int test[TEST_LENGTH] = {
		1, 17, 972, 50, 98,
		98, 50, 972, 17, 1
	};

	listint_t *head;

	head = NULL;
	build_test_list(&head, test);
	print_listint(head);

	if (is_palindrome(&head) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");

	free_listint(head);

	return (0);
}

/**
 * build_test_list - builda a linked list from an array
 *@head: head node of the linked list
 *@test: array with test values
 *
 */

void build_test_list(listint_t **head, int *test)
{
	int index;

	for (index = 0; index < TEST_LENGTH; index++)
		add_nodeint_end(head, test[index]);
}
