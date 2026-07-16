#include "unity.h"
#include "lists.h"

TEST_SOURCE_FILE("src/linked_list/update_node.c")
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
 * test_update_in_empty_list - Test updating a node in an empty list
 */
void test_update_in_empty_list(void)
{
	list_t *head = NULL;

	TEST_ASSERT_EQUAL_PTR(NULL, update_node(head, "key:1", "value:1"));
}

/**
 * test_update_nonexistent_node - Test updating a node that does not exist in the list
 */
void test_update_nonexistent_node(void)
{
	list_t *head = NULL;

	add_node(&head, "key:1", "value:1");

	TEST_ASSERT_EQUAL_PTR(NULL, update_node(head, "key:2", "value:2"));
}

/**
 * test_update_in_multi_node_list - Test updating an existing node in a multi-node list
 */
void test_update_in_multi_node_list(void)
{
	list_t *head = NULL, *node = NULL;
	char value[] = "value:new";

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	node = update_node(head, "key:2", value);

	TEST_ASSERT_NOT_NULL(node);
	TEST_ASSERT_EQUAL_STRING(value, node->v);
}

/**
 * test_update_string_is_copied - Test that the updated string is copied and not just referenced
 */
void test_update_string_is_copied(void)
{
	list_t *head = NULL, *node = NULL;
	char value[20] = "value:new";

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	node = update_node(head, "key:2", value);

	TEST_ASSERT_NOT_NULL(node);
	TEST_ASSERT_EQUAL_STRING(value, node->v);

	/* mutate original value and check if node's value remains unchanged */
	strcpy(value, "value:changed");

	TEST_ASSERT_TRUE(strcmp(value, node->v) != 0);
}
