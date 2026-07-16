#include "lists.h"

/**
 * update_node - update the value of a node using a given key
 * @h: pointer to head of the list
 * @k: key to search for
 * @v: new value to set
 *
 * Return: the updated node if successful else NULL
 */
list_t *update_node(list_t *h, const char *k, const char *v)
{
	list_t *tmp = 0;

	tmp = find_node(h, k);
	if (tmp == NULL)
		return (NULL);

	free(tmp->v);
	tmp->v = strdup(v);
	if (tmp->v == NULL)
		return (NULL);

	return (tmp);
}
