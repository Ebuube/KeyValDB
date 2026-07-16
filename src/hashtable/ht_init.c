#include "hashtable.h"
#include <stdlib.h>

/**
 * ht_init - Initializes a hash table with default size if not given
 * @size: Size of the hash table
 *
 * Return: Pointer to the initialized hash table, or NULL on failure
 */
hash_table_t *ht_init(size_t size)
{
	hash_table_t *ht = NULL;

	if (size == 0)
		size = HT_DEFAULT_SIZE;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->buckets = calloc(size, sizeof(list_t *));
	if (ht->buckets == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;

	return (ht);
}
