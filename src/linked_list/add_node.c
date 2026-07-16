#include "lists.h"

/**
 * add_node - add a node to the beginning of a list_t list
 * @h: pointer to head of the list
 * @k: string key of the new node
 * @v: string value of the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **h, const char *k, const char *v)
{
	list_t *new = NULL;

	if (!h || !k || !v)
		return (NULL);

	/* Create and initialize node */
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->k = strdup(k);
	new->v = strdup(v);
	if (!new->k || !new->v)
	{
		free(new->k);
		free(new->v);
		free(new);
		return (NULL);
	}

	/* Insert node at beginning of the list */
	new->next = *h;
	(*h) = new;
	return (new);
}
