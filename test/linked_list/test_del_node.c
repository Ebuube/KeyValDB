#include "unity.h"
#include "lists.h"

TEST_SOURCE_FILE("src/linked_list/add_node.c")
TEST_SOURCE_FILE("src/linked_list/del_node.c")

/* Called before each test */
void setUp(void)
{
}

/* Called after each test */
void tearDown(void)
{
}

/**
 * test_del_from_null_list - Test deleting a node from a NULL list
 */
void test_del_from_null_list(void)
{
	TEST_ASSERT_FALSE(del_node(NULL, "key:1"));
}

/**
 * test_del_from_empty_list - Test deleting a node from an empty list
 */
void test_del_from_empty_list(void)
{
	list_t *list = NULL;

	TEST_ASSERT_FALSE(del_node(&list, "key:1"));
}

/**
 * test_del_null_key - Test deleting a node with a NULL key
 */
void test_del_null_key(void)
{
	list_t *list = NULL;

	add_node(&list, "key:1", "value:1");

	TEST_ASSERT_FALSE(del_node(&list, NULL));
}

/**
 * test_del_nonexisting_key - Test deleting a node with a non-existing key
 */
void test_del_nonexisting_key(void)
{
	list_t *list = NULL;

	add_node(&list, "key:1", "value:1");

	TEST_ASSERT_FALSE(del_node(&list, "key:2"));
}

/**
 * test_del_head_node - Test deleting head node from non-empty list
 */
void test_del_head_node(void)
{
	list_t *head = NULL, *node2 = NULL;

	add_node(&head, "key:1", "value:1");
	node2 = add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	TEST_ASSERT_TRUE(del_node(&head, "key:3"));
	TEST_ASSERT_EQUAL_PTR(node2, head);
}

/**
 * test_del_middle_node - Test deleting middle node from non-empty list
 */
void test_del_middle_node(void)
{
	list_t *head = NULL, *tail = NULL;

	tail = add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	TEST_ASSERT_TRUE(del_node(&head, "key:2"));
	TEST_ASSERT_EQUAL_PTR(tail, head->next);
}

/**
 * test_del_tail_node - Test deleting tail node from non-empty list
 */
void test_del_tail_node(void)
{
	list_t *head = NULL;

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	TEST_ASSERT_TRUE(del_node(&head, "key:1"));
	TEST_ASSERT_NULL(head->next->next);
}

/**
 * test_del_only_node_in_list - Test deleting the only node in a list
 *
 * Description: Ensure head is set to NULL after
 */
void test_del_only_node_in_list(void)
{
	list_t *head = NULL;

	add_node(&head, "key:1", "value:1");

	TEST_ASSERT_TRUE(del_node(&head, "key:1"));
	TEST_ASSERT_NULL(head);
}

/**
 * test_del_first_match - Test second match is spared if any
 */
void test_del_first_match(void)
{
	list_t *head = NULL, *match2 = NULL;

	match2 = add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:1", "value:3");

	TEST_ASSERT_TRUE(del_node(&head, "key:1"));
	TEST_ASSERT_EQUAL_STRING("key:2", head->k);
	TEST_ASSERT_NOT_NULL(match2);
	TEST_ASSERT_EQUAL_PTR(match2, head->next);
}
