#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
int print_list(const list_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		printf("Key: %s, Value: %s\n", h->k, h->v);
		h = h->next;
		count++;
	}

	return (count);
}
