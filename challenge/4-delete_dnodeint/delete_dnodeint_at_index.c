#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;
	i = 0;

	while (node != NULL && i < index)
	{
		node = node->next;
		i++;
	}

	if (node == NULL)
		return (-1);

	if (node->prev != NULL)
	{
		/*
		 * The previous node must point to the node after the deleted one.
		 * The original code changed prev->prev, which broke the list links.
		 */
		node->prev->next = node->next;
	}
	else
	{
		*head = node->next;
	}

	if (node->next != NULL)
	{
		/*
		 * The next node must point back to the node before the deleted one.
		 * This must be done before freeing node to avoid using freed memory.
		 */
		node->next->prev = node->prev;
	}

	free(node);

	return (1);
}
