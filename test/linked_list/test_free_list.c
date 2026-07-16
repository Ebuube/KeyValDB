#include "unity.h"
#include "lists.h"

TEST_SOURCE_FILE("src/linked_list/add_node.c")
TEST_SOURCE_FILE("src/linked_list/free_list.c")

/* Called before each test */
void setUp(void)
{
}

/* Called after each test */
void tearDown(void)
{
}

/**
 * test_free_null - Test when NULL is passed, should not crash
 */
void test_free_null(void)
{
	free_list(NULL);
}

/**
 * test_free_empty_list - Test when empty list is passed, should not crash
 */
void test_free_empty_list(void)
{
	list_t *head = NULL;
	free_list(&head);
	TEST_ASSERT_NULL(head);
}

/**
 * test_free_single_node_list - Test freeing a list with only one node
 *
 * Description: Head is set to NULL after freeing the list.
 */
void test_free_single_node_list(void)
{
	list_t *head = NULL;

	add_node(&head, "key:1", "value:1");

	TEST_ASSERT_NOT_NULL(head);

	free_list(&head);

	TEST_ASSERT_NULL(head);
}

/**
 * test_free_multi_node_list - Test freeing a list with more than one node
 *
 * Description: Ensures list is properly traversed
 */
void test_free_multi_node_list(void)
{
	list_t *head = NULL;

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");
	add_node(&head, "key:3", "value:3");

	TEST_ASSERT_NOT_NULL(head);

	free_list(&head);

	TEST_ASSERT_NULL(head);
}
