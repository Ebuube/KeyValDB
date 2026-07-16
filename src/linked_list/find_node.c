#include "lists.h"

/**
 * find_node - find a node using a given key
 * @h: pointer to head of the list
 * @k: key to search for
 *
 * Return: point to the node or NULL if not found
 */
list_t *find_node(list_t *h, const char *k)
{
	while (h)
	{
		if (strcmp(h->k, k) == 0)
			return (h);
		h = h->next;
	}

	return (NULL);
}
