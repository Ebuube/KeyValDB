#include "lists.h"

/**
 * del_node - delete the first node whose key matches k
 * @h: address of head node
 * @k: key of node to delete
 *
 * - if key found in head node, delete head node and update head pointer
 *
 * Return: address of head node or NULL if key not found
 */
bool del_node(list_t **h, const char *k)
{
	list_t *tmp = *h;
	list_t *prev = NULL;

	if (h == NULL || *h == NULL || k == NULL)
		return (false);

	/* find node with key k */
	while (tmp != NULL && strcmp(tmp->k, k) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	/* key not found */
	if (tmp == NULL)
		return (false);

	/* key found in head node */
	if (prev == NULL)
		(*h) = tmp->next;
	else
		prev->next = tmp->next;

	free(tmp->k);
	free(tmp->v);
	free(tmp);

	return (true);
}
