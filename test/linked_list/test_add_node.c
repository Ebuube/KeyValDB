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
