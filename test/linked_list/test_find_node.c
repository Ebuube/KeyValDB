#include "unity.h"
#include "lists.h"

TEST_SOURCE_FILE("src/linked_list/add_node.c")
TEST_SOURCE_FILE("src/linked_list/find_node.c")

/* Called before each test */
void setUp(void)
{
}

/* Called after each test */
void tearDown(void)
{
}

/**
 * test_find_in_empty_list - Test that find_node returns NULL when the list is empty
 */
void test_find_in_empty_list(void)
{
	TEST_ASSERT_EQUAL(NULL, find_node(NULL, "key:1"));
}

/**
 * test_find_key_in_head_node - Test that find_node can find a key in the head node
 */
void test_find_key_in_head_node(void)
{
	list_t *head = NULL, *node = NULL;
	char key[] = "key:1", value[] = "value:1";

	add_node(&head, key, value);

	node = find_node(head, key);

	TEST_ASSERT_NOT_NULL(node);
	TEST_ASSERT_EQUAL_STRING(key, node->k);
	TEST_ASSERT_EQUAL_STRING(value, node->v);
}

/**
 * test_find_key_in_middle_node - Test that find_node can find a key in the middle node
 */
void test_find_key_in_middle_node(void)
{
	list_t *head = NULL, *node = NULL;

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	node = find_node(head, "key:2");

	TEST_ASSERT_NOT_NULL(node);
	TEST_ASSERT_EQUAL_STRING("key:2", node->k);
	TEST_ASSERT_EQUAL_STRING("value:2", node->v);
}

/**
 * test_find_key_in_tail_node - Test that find_node can find a key in the tail node
 */
void test_find_key_in_tail_node(void)
{
	list_t *head = NULL, *node = NULL;

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	node = find_node(head, "key:3");

	TEST_ASSERT_NOT_NULL(node);
	TEST_ASSERT_EQUAL_STRING("key:3", node->k);
	TEST_ASSERT_EQUAL_STRING("value:3", node->v);
}

/**
 * test_key_not_found - Test that find_node returns NULL when the key is not found
 */
void test_key_not_found(void)
{
	list_t *head = NULL, *node = NULL;

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	node = find_node(head, "key:4");

	TEST_ASSERT_NULL(node);
}

/**
 * test_find_case_sensitive_key - Test that find_node is case-sensitive
 */
void test_find_case_sensitive_key(void)
{
	list_t *head = NULL, *node = NULL;

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	node = find_node(head, "KEY:2");

	TEST_ASSERT_NULL(node);
}
