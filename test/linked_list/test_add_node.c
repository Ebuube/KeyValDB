#include "unity.h"
#include "lists.h"

TEST_SOURCE_FILE("src/linked_list/add_node.c")

/* Called before each test */
void setUp(void)
{
}

/* Called after each test */
void tearDown(void)
{
}

void test_add_to_empty_list(void)
{
	list_t *head = NULL, *node = NULL;
	char *key = "user:1", *value = "{\"name\": \"Alice\", \"age\": 30}";

	node = add_node(&head, key, value);

	TEST_ASSERT_NOT_NULL(node);
	TEST_ASSERT_NOT_NULL(head);

	TEST_ASSERT_EQUAL_PTR(node, head);

	TEST_ASSERT_EQUAL_STRING(key, node->k);
	TEST_ASSERT_EQUAL_STRING(value, node->v);

	TEST_ASSERT_NULL(node->next);
}

void test_add_to_non_empty_list(void)
{
	list_t *head = NULL, *first = NULL, *second = NULL;

	first = add_node(&head, "user:1", "Emeka");
	second = add_node(&head, "user:2", "Ebube");

	TEST_ASSERT_NOT_NULL(second);
	TEST_ASSERT_EQUAL_PTR(second, head);

	/* new node should point to previous head */
	TEST_ASSERT_EQUAL_PTR(first, second->next);

	/* old head's data should be untouched */
	TEST_ASSERT_EQUAL_STRING("user:1", first->k);
	TEST_ASSERT_EQUAL_STRING("Emeka", first->v);
	TEST_ASSERT_NULL(first->next);
}

void test_add_node_null_head(void)
{
	list_t *node = NULL;

	node = add_node(NULL, "user:1", "Emeka");

	TEST_ASSERT_NULL(node);
}

void test_add_node_null_key(void)
{
	list_t *head = NULL, *node = NULL;

	node = add_node(&head, NULL, "Emeka");

	TEST_ASSERT_NULL(node);
	TEST_ASSERT_NULL(head);
}

void test_add_node_null_value(void)
{
	list_t *head = NULL, *node = NULL;

	node = add_node(&head, "user:1", NULL);

	TEST_ASSERT_NULL(node);
	TEST_ASSERT_NULL(head);
}

void test_add_node_copies_strings(void)
{
	list_t *head = NULL, *node = NULL;
	char key[10] = "user:1", value[10] = "Emeka";

	node = add_node(&head, key, value);

	/* mutate the originals after insertion */
	strcpy(key, "changed");
	strcpy(value, "changed");

	/* assert node's key and value are unchanged */
	TEST_ASSERT_EQUAL_STRING("user:1", node->k);
	TEST_ASSERT_EQUAL_STRING("Emeka", node->v);
}
