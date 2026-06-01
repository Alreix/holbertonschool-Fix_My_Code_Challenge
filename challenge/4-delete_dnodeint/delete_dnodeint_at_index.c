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
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	i = 0;

	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	/*
	 * If current->prev is not NULL, the node is not the first one.
	 * So we connect the previous node to the next node.
	 */
	if (current->prev != NULL)
		current->prev->next = current->next;
	else
		*head = current->next;

	/*
	 * If current->next is not NULL, the node is not the last one.
	 * So we connect the next node back to the previous node.
	 */
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);

	return (1);
}