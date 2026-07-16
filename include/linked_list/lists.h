#ifndef _LISTS_H
#define _LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct list_s - singly linked list
 * @k: identifier
 * @v: value associated with the k
 * @next: points to next node
 *
 * Description: singly linked list of key/value pairs, insertion is LIFO, keys are not unique, strings are owned copies and not aliases
 */
typedef struct list_s
{
	char *k;
	char *v;
	struct list_s *next;
} list_t;

/* Functions */
list_t *add_node(list_t **h, const char *k, const char *v);
void free_list(list_t **h);
list_t *find_node(list_t *h, const char *k);
list_t *update_node(list_t *h, const char *k, const char *v);
int print_list(const list_t *h);
bool del_node(list_t **h, const char *k);

#endif /* _LISTS_H */
