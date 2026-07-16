#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "lists.h"

/**
 * struct hash_table_s - hash table data structure
 * @buckets: array of pointers to head of linked lists
 * @size: size of the array
 *
 * Description: hash table data structure that uses separate chaining for
 * collision resolution, where each bucket is a linked list of key/value pairs
 * and keys are unique
 */
typedef struct hash_table_s
{
	list_t **buckets;
	size_t size;
} hash_table_t;

/* Functions */
unsigned long hash_djb2(const char *str);
#endif /* _HASHTABLE_H */
