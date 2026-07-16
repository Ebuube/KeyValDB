#include "lists.h"

/**
 * free_list - free all nodes in a list_t list
 * @h: pointer to head of the list
 *
 * Return: void
 */
void free_list(list_t **h)
{
	list_t *tmp;

	if (h == NULL)
		return;

	while (*h != NULL)
	{
		tmp = (*h)->next;
		free((*h)->k);
		free((*h)->v);
		free(*h);

		(*h) = tmp;
	}
}
